/*
    edges[i] = [fromi, toi, weighti] 
    represents a bidirectional and weighted edge

    means this is undirected weighrted grpah.........


    Return the city with the smallest number of cities 
    that are reachable through some path and whose distance is at most distanceThreshold


    this line means we have to checck
    how many city reacable from node x 
    with atmost(not more than) threshold...........

    so how can we check this for evrey node

    multisource + shortest distance = floyd warshall

    edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]] distanceThreshold = 4
        make it directional graph

    bcoz floyd warshall on works on DG

    [0,1,3]
    [1,0,3]
    [1,2,1][2,1,1][1,3,4][3,1,4]
    [2,3,1]
    [3,2,1]

    now make the Final Floyd-Warshall Matrix

        distanceThreshold = 4

    [0,3,4,5] -> 2 cities
    [3,0,1,2] -> 3 cities
    [4,1,0,1] -> 3 cities
    [5,2,1,0] -> 2 cities

    "smallest number of cities that are reachable"
    means citie 0 and 3 have smallest number of cities reacable.....

    If there are multiple such cities, return the city with the greatest number.
        3 > 1

    so city 3 will be answer

*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // distance to itself
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        // fill edges
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd Warshall
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] + dist[via][j] < dist[i][j]){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }

        int city = -1;
        int minCount = INT_MAX;

        for(int i = 0; i < n; i++){
            int count = 0;

            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold)
                    count++;
            }

            // remove itself [0][0]..[1][1]..[2][2]......
            count--;

            if(count <= minCount){
                minCount = count;
                city = i;
            }
        }

        return city;
    }
};
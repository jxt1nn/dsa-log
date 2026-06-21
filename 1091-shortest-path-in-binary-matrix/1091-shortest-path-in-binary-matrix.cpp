/*
    A clear path in a binary matrix is
        a path from the top-left cell (i.e., (0, 0)) to 
            bottom-right cell (i.e., (n - 1, n - 1))

    All the visited cells of the path are 0

        this means we can only walk on 0

    All the adjacent cells of the path are 8-directionally connected
    (i.e., they are different and they share an edge or a corner).

    we can move only on 0 cells....

    and we can move in 8 directions 

    (-1,-1)  ↖
    (-1, 0)  ↑
    (-1, 1)  ↗
    ( 0,-1)  ←
    ( 0, 1)  →
    ( 1,-1)  ↙
    ( 1, 0)  ↓
    ( 1, 1)  ↘

    we want the shortest distance.....

    dijkstra algo..

    step of Dijkstra:

    1. priority quque ->  src and dist
       and dist vector -> dist[src] = 0
        pop

    2. then check all its adj
    3. if olddist + edge w < dist[node] 
    4. we push into pq and modify the distance

    now we impiliment dijkstra according to this question......

    put src and dist in pq

    then pop it

    check all 8 directions:
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};


    if(inBoundry && m[i][j] == 0){
        check the new distance 
        if its less put it into pq 
    }
    otherwise skip it.........

    do this untill pq is empty

    at the end return dist[n-1][m-1]
    

    prioirty queue store something like this

            {{i,j},dist} pair<pair<int,int>,int>

    So:
    it.first.first → row (i)
    it.first.second → column (j)
    it.second → distance (d)

    edge case :

        if(0,0 == 1 || n-1,m-1) return -1;

    we can do this question with simple BFS 
        bcoz distance from cell is :
        
        All 1 → BFS enough
        Different → Need Dijkstra
        Negative → Need Bellman-Ford
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<pair<int,int>, int>,
            vector<pair<pair<int,int>, int>>,
            greater<pair<pair<int,int>, int>>
        > pq;

        pq.push({{0,0}, 1});   // start distance = 1
        dist[0][0] = 1;

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int i = it.first.first;
            int j = it.first.second;
            int d = it.second;

            if(i == n-1 && j == n-1)
                return d;

            for(int k = 0; k < 8; k++){
                int newX = i + dx[k];
                int newY = j + dy[k];

                if(newX >= 0 && newX < n &&
                   newY >= 0 && newY < n &&
                   grid[newX][newY] == 0 &&
                   d + 1 < dist[newX][newY]) {

                    dist[newX][newY] = d + 1;
                    pq.push({{newX,newY}, d+1});
                }
            }
        }

        return -1;
    }
};
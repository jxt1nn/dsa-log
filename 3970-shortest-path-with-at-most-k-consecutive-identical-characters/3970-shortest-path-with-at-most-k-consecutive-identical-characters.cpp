/*

    we have to reach 0 to n-1 
    and have a string of length n-1

    every node have 1 charchter of this string 

    means str[0] to 0 node
    str[1] to 1 node 

    like this.................


    we have to Return the minimum total edge weight of a path from node 0 to node n - 1
    such that the concatenation of the labels of the nodes along the path
    contains at most k consecutive identical characters. 

    we have to check if current consective identical count is <= k


    State:

        (node,
        consecutiveCount)

        Store

        dist[node][consecutiveCount]

        because reaching the same node with
        different consecutive counts gives
        different future possibilities.


    Transition:

        newCost = currCost + edgeWeight

        If labels[next] == labels[curr]
            newCount = currCount + 1

        else
            newCount = 1

        If(newCount > k)
            skip



    Priority:

        minimum cost first
        (minHeap)


    Relaxation:

        if(newCost < dist[next][newCount])
            update



*/
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &x : edges){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<vector<long long>> dis(n,vector<long long>(k+1,LLONG_MAX));

        priority_queue<tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<tuple<long long,int,int>>> pq;

        int ch = s[0] - 'a';

        dis[0][1]= 0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d,u,cnt] = pq.top();
            pq.pop();

            if(d >dis[u][cnt]) continue;

            if(u == n -1) return d;

            for(const auto& edges : adj[u]){
                int v = edges.first;
                int wei = edges.second;
                
                int ncnt = s[v] == s[u] ? cnt+1 : 1;

                if(ncnt > k) continue;
                
                int newWeight = d + wei;

                if(newWeight < dis[v][ncnt]){
                    dis[v][ncnt] = d + wei;
                    pq.push({d+wei,v,ncnt});
                }
            }
        }
        return -1;
    }
};
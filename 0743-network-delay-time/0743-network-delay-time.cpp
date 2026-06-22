/*

    just dijkstra....

*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
         // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for(auto &t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if(time > dist[node]) continue;

            for(auto &it : adj[node]){

                int nextNode = it.first;
                int weight = it.second;
                
                if(dist[node] + weight < dist[nextNode]){
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }

        int maxi = 0;

        for(int i =1;i<dist.size();i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};
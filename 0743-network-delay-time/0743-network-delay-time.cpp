/*
    You are given a network of n nodes, labeled from 1 to n

    times[i] = (ui, vi, wi), where ui is the source node, 
    vi is the target node, and 
    wi is the time it takes for a signal to travel from source to target.

    basically its a Shortest Path in Directed Weighted Graph problemm........

    We will send a signal from a given node k

    return the minimum time it takes for all the n nodes to receive the signal

    If it is impossible for all the n nodes to receive the signal, return -1.


    Graph is directed
    Edges have weights
    We need minimum total time

    🔥 Dijkstra’s Algorithm

    we find the shoretst distance from src node k 
        for all the nodes........

    after that when we finished........

    dist[i] = shortest time from k to i

    we travwerse in distance array 
        if any one still infinity we return -1 

    otherwise maximum of all the elements in distance vectror....
    
    what we store in pq?????????

        {time,node}
    
    if(time > dist[node]) continue;
    
    just to skip unnecessary nodes........

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
        
        // Step 2: Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // Step 3: Min heap (time, node)
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        
        pq.push({0, k});
        
        // Step 4: Dijkstra
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int time = top.first;
            int node = top.second;
            
            // Ignore outdated entries
            if(time > dist[node]) continue;
            
            for(auto &it : adj[node]){
                int nextNode = it.first;
                int weight = it.second;
                
                if(dist[node] + weight < dist[nextNode]){
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        // Step 5: Find answer
        int maxTime = 0;
        
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};
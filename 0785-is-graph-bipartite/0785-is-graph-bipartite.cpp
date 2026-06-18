/*   
    we have a undirected graph...
        we have to check its bipartite or not..

    when a undirected t=graph bipartite ??

        2 adjacent node should not be same........

    means..
        label node as 0 and 1 
    
    0 1 0 1 0 1  
        not any adjacent nodee is same 
    
    by doing dry run in notebook
        we finds out......
    
    odd length cycle : not bipartite 
    even lengrht cycle : is bipartite  
    linear graph : is bipartite 

    DONE....... with DFS 

    now doing with BFS........

    what BFS need???

    1. queue -> source
    2. visited array 
    3. BFS 

    what is the source?????????
        already have adj list.....

    push the first element

*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, -1);   // -1 means uncolored
        
        for (int i = 0; i < n; i++) {
            
            if (vis[i] == -1) {   // new component
                
                queue<int> q;
                q.push(i);
                vis[i] = 0;      // color start node
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int nei : adj[node]) {
                        
                        if (vis[nei] == -1) {
                            vis[nei] = !vis[node];
                            q.push(nei);
                        }
                        else if (vis[nei] == vis[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

// class Solution {
// public:
//     bool dfs(int i, int color, vector<vector<int>>& graph, vector<int>& vis) {
        
//         vis[i] = color;
        
//         for (auto node : graph[i]) {  
            
//             if (vis[node] == -1) { 
//                 if (dfs(node, !color, graph, vis) == false) {
//                     return false;
//                 }
//             }
//             else if (vis[node] == color) {  
//                 // if neighbour has same color → not bipartite
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> vis(n, -1);  // -1 means not colored bcoz we already using 0 
        
//         for (int i = 0; i < n; i++) {
//             if (vis[i] == -1) {
//                 if (dfs(i, 0, graph, vis) == false) {
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }
// };

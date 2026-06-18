/*
    A node is a terminal node if there are no outgoing edges.

    A node is a safe node:
    if every possible path starting from that node leads to a terminal node 

    BY doing the dry run in nOTEBOOK

    we finds out that :
        anyone part of the cycle 
            OR 
        leads to a cycle cannot be SAFE NODE

    other than everyone is safe node...........

    SO how can we find that node that are :

    part of cycle OR leads to a cycle

    ---------------------------------------

    so we know how to detect cycle in directed graph by DFS 

    but we stopped when we find the cycle but this time 
        we have to traverse the whole tree..........

    DFS + vis + pathVis 
        if (visited AND pathVis) cycle 

    SO we have to mark the this node 
        AND 
    all the node that present in this path..........

    HOW??????????????

    SO we can do one thing
        when  ever we get a cycle 
    
    we doesnt change the pathVis back to 0 
        we keep it as 1 

    and all the other node also that comes in that cycle path 

    !!!!!!

    if (! vis){
        if(dfs == true){
            return true : find cycle 
        }
    }
    else if (path vis){
        return true : find cycle 
    }

    at the end if their is no cycle mark NODE 1 in seprate array......

    vis[i]      → node already visited
    pathVis[i]  → node currently in DFS path (recursion stack)
    check[i]    → 1 = safe node, 0 = unsafe
        

    DONE-------------------

    now do this with 
        BFS -> TOPO SORT

    what we do in topo sort 
        store indgree of nodes
        push nodes which indegree is 0 into QUEUE
        start bfs from this node 
        and reduce indgree of their adj nodes
            and if its indgree gets 0 push it into queue   
        
        and when ever we pop from queue 
            store it for answer 
            (this is our topo sort)




    now we know what a terminal node
        no outgoing edges 
    
    means if we reverse it 
        this became zero indgree 

    their we get clicked topo sort 
        reverse the graph all edges 

    NOW, 
        no simple topo sort on this  graph 
*/

//BFS - TOPO SORT
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> adj(n);   
        vector<int> inDegree(n, 0);
        
        // reverse the graph
        for(int i = 0; i < n; i++){
            for(int nei : graph[i]){
                adj[nei].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        // push terminal nodes (original outdegree = 0)
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int nei : adj[node]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//DFS - vis and pathVIS
// class Solution {
// public:
// bool dfs(int node, vector<vector<int>>& graph,
//              vector<int>& vis,
//              vector<int>& pathVis,
//              vector<int>& check) {
        
//         vis[node] = 1;
//         pathVis[node] = 1;
        
//         for (int neighbor : graph[node]) {
            
//             // If not visited, do DFS
//             if (!vis[neighbor]) {
//                 if (dfs(neighbor, graph, vis, pathVis, check))
//                     return true;   // cycle found
//             }
            
//             // If visited and still in current path → cycle
//             else if (pathVis[neighbor]) {
//                 return true;  // cycle found
//             }
//         }
        
//         // No cycle found → mark safe
//         check[node] = 1;
//         pathVis[node] = 0;   // remove from current path
        
//         return false;  // no cycle
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();    
        
//         vector<int> vis(n, 0);
//         vector<int> pathVis(n, 0);
//         vector<int> check(n, 0);
        
//         for (int i = 0; i < n; i++) {
//             if (!vis[i])
//                 dfs(i, graph, vis, pathVis, check);
//         }
        
//         vector<int> result;
//         for (int i = 0; i < n; i++) {
//             if (check[i] == 1)
//                 result.push_back(i);
//         }
        
//         return result;
//     }
// };
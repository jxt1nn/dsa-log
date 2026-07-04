/*

    Return the minimum possible score of a path between cities 1 and n
   score of a path between two cities is defined as the minimum distance of a road in this path.


    SO,

    this is graph problem 
    Graph

    Need minimum score.

    Score

    =

    minimum edge in the path.

                
                Important observation

    We may revisit roads.

    Therefore

    we can traverse any edge inside the connected component.

    Hence
    Answer
    =
    minimum edge weight
    among all edges
    in the connected component
    containing node 1.

    The cities graph is not necessarily connected

    SO, we have to connected it first
    ----------DSU--------------

    It is allowed for a path to contain the same road multiple times, 
    and you can visit cities 1 and n multiple times along the path.

    we can revisit any node any number of times 
    SO,....................

    1 ----(8)---- 2 ----(7)---- n
    min(8,7) = 7

    1 --(8)-- 2 --(7)-- n
        |
        (2)
        |
        3

    Normally, the path from 1 to n is  :  1 → 2 → n
    min(8,7)=7

    But the problem says you may revisit roads.
    So you can take this path:  1 → 2 → 3 → 2 → n

    min(8,2,2,7) = 2
We intentionally included the smallest edge.


    Once you enter a connected component,

    you are free to walk around inside it.

    You can visit

    any node
    any edge
    come back
    continue to n

SO, we have to travese the 1's component and find the minimum edge 

    1 ---- 2 ---- 3 ---- n

    4 ---- 5    

    Component A

        1
        2
        3
        n
    
    Component B

        4
        5

    Can we visit :    4 ?

    NOOOOOOOOOOOOOOOOOO

    Because it's in another connected component.
    Therefore,
    only edges in city 1's connected component are reachable.

    WE CAN DO THIS BY SIMPLE BFS

*/
class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // Initially every node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find the ultimate parent (leader) of a node
    int findParent(int node) {

        if (node == parent[node]) {
            return node;
        }

        // Path Compression
        return parent[node] = findParent(parent[node]);
    }

    // Merge two connected components
    void unionBySize(int u, int v) {

        int parentU = findParent(u);
        int parentV = findParent(v);

        // Already in the same component
        if (parentU == parentV) {
            return;
        }

        // Attach the smaller component to the larger one
        if (size[parentU] < size[parentV]) {

            parent[parentU] = parentV;
            size[parentV] += size[parentU];

        } else {

            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        
        DSU ds(n);

        for(auto &it : edges){
            
            int u = it[0];
            int v = it[1];

            ds.unionBySize(u,v);
        }

        int component = ds.findParent(1);
        int ans = INT_MAX;

        for(auto &it : edges){
            int u = it[0];
            int wt = it[2];

            if(ds.findParent(u) == component){
                ans = min(ans,wt);
            } 
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : adj[node]){
                int v = it.first;
                int dis = it.second;

                ans = min(ans, dis);

                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};






*/
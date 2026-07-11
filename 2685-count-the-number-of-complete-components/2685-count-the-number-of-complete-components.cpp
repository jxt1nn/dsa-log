class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             int& nodes, int& edges) {

        vis[node] = 1;
        nodes++;

        edges += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int complete = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                int nodes = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodes, edgeCount);

                edgeCount /= 2;  // undirected graph

                long long requiredEdges =
                    1LL * nodes * (nodes - 1) / 2;

                if (edgeCount == requiredEdges) {
                    complete++;
                }
            }
        }

        return complete;
    }
};
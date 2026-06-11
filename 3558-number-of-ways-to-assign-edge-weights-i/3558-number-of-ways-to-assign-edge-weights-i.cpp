class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        const int MOD = 1e9 + 7;

        vector<vector<int>> graph(n + 1);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(1);

        vector<int> visited(n + 1, 0);
        visited[1] = 1;

        int levels = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int nbr : graph[node]) {
                    if (!visited[nbr]) {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }

            levels++;
        }

        int maxDepth = levels - 1;

        long long ans = 1;
        for (int i = 1; i < maxDepth; i++) {
            ans = (ans * 2) % MOD;
        }

        return (int)ans;
    }
};
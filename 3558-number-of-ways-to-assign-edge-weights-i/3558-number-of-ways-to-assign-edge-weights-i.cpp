class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n + 1, -1);
        queue<int> q;

        q.push(1);
        depth[1] = 0;

        int maxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (depth[nei] == -1) {
                    depth[nei] = depth[node] + 1;
                    maxDepth = max(maxDepth, depth[nei]);
                    q.push(nei);
                }
            }
        }

        if (maxDepth == 0) return 0;   // no edge in the path

        return (int)modPow(2, maxDepth - 1);
    }
};
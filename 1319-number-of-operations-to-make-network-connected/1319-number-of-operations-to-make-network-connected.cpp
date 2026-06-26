class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int extra = 0;

        // Count extra cables
        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v))
                extra++;
            else
                ds.unionBySize(u, v);
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                components++;
        }

        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};
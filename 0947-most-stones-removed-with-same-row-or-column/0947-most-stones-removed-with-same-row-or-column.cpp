/*
    Read the statement like this:

    Don't think about "Removing Stones".

    Think:

        "How many Connected Components are there?"

    -----------------------------------------------------------
    When are two stones connected?
    -----------------------------------------------------------

    Two stones are connected if:

        Same Row
            OR
        Same Column

    Code:

    if(stones[i][0] == stones[j][0] ||
    stones[i][1] == stones[j][1])

    Meaning

        Row(i) == Row(j)
                OR
        Col(i) == Col(j)

    Then

        Merge both stones using DSU.

    -----------------------------------------------------------
    Why DSU?
    -----------------------------------------------------------

    Every connected stone belongs to the same component.

    DSU helps us merge all stones that are connected
    by row or column.

    -----------------------------------------------------------
    Building Components
    -----------------------------------------------------------

    Example

    (0,0)
    (0,2)
    (1,2)
    (3,3)

    Connections

    (0,0) ---- (0,2)
                |
                (1,2)

    (3,3)

    Components = 2

    -----------------------------------------------------------
    Most Important Observation
    -----------------------------------------------------------

    Inside one connected component,

    We can remove every stone

    EXCEPT ONE.

    Why?

    Because the last stone has no other stone
    left to share its row or column.

    Therefore

    One component
            ↓
    One remaining stone

    -----------------------------------------------------------
    Formula
    -----------------------------------------------------------

    Suppose

    Total Stones = N

    Connected Components = C

    Maximum Stones Removed

    = N - C


*/
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
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        DisjointSet ds(n);

        // Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            int row1 = stones[i][0];
            int col1 = stones[i][1];

            for (int j = i + 1; j < n; j++) {
                int row2 = stones[j][0];
                int col2 = stones[j][1];

                if (row1 == row2 || col1 == col2) {
                    ds.unionBySize(i, j);
                }
            }
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                components++;
        }

        return n - components;
    }
};

/*
DFS APPROACH 


class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& stones) {
        visited[node] = 1;
        for (int j = 0; j < stones.size(); j++) {
            if (!(visited[j]) &&
                (stones[j][0] == stones[node][0] || stones[j][1] == stones[node][1])) {
                dfs(j, visited, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, stones);
            }
        }
        return n - count;
    }
};

*/
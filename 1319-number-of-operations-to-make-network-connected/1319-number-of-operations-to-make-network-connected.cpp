/*
    We are processing every cable (u, v).

    Question:
        Are u and v already connected?

    We check:

        if(ds.findUPar(u) == ds.findUPar(v))

    findUPar(node)
        -> Returns the Ultimate Parent (Leader) of that node.
        -> If two nodes have the same Ultimate Parent,
           they belong to the SAME connected component.

    --------------------------------------------

    Case 1:

        findUPar(u) == findUPar(v)

    Example:

            0 ----- 1
             \     /
               2

    Edges:
        (0,1)
        (1,2)
        (0,2)

    When we process (0,2),

        findUPar(0) == findUPar(2)

    because

        0 and 2 are already connected
        through node 1.

    Therefore,

        This edge creates a cycle.

    It is NOT needed to keep the graph connected.

    We can remove this cable and use it somewhere else.

    So,

        extra++;

    means

        We found one extra (redundant) cable.

    --------------------------------------------

    Case 2:

        findUPar(u) != findUPar(v)

    Example:

        0 ----- 1

        2 ----- 3

    Processing edge:

        (1,2)

    Here,

        findUPar(1) != findUPar(2)

    because

        They belong to different components.

    So this cable is useful.

    Merge both components.

        ds.unionBySize(u,v);

    --------------------------------------------

    Easy Way to Remember

        Same Parent
            -> Already Connected
            -> Cycle
            -> Extra Cable

        Different Parent
            -> Different Components
            -> Merge Them
            -> unionBySize()
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
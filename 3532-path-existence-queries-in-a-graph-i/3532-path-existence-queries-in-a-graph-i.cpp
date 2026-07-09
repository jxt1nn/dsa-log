/*

    at starting every one is indivial nodes

    than,
    |nums[i] - nums[j]| <= maxDiff 

    check this for if tehir is edge presnt or not 
    if present

        check if they belong to same parent 

    if yes -> dont do anything
    otherwise -> connect them by DSU 

    afetr this process quesries and check if u and v have a same parent or not 
    if this is truec -> their will be an edge 
    otherwise -> false and no edge presnt 


    Initially:

    Every node is its own component.

    parent[i] = i


    nums is SORTED.
    Instead of checking every pair,

    only check adjacent elements.

    Why?
    If
    nums[i+1] - nums[i] > maxDiff
    then every element after i+1 is even larger.
    So node i cannot connect to any later node.


    For every adjacent pair
    if(nums[i+1] - nums[i] <= maxDiff)
        unionBySize(i, i+1);

    This gradually builds all connected components.

    Now answer each query.

    For query(u,v)

    if(findUPar(u) == findUPar(v))
        return true;
    else
        return false;


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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        DisjointSet ds(n);

        for(int i = 0; i <= n-2 ;i++){
            int diff = abs(nums[i] - nums[i+1]);

            if(diff <= maxDiff){
                ds.unionBySize(i,i+1);
            }
        }

        vector<bool> ans;

        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
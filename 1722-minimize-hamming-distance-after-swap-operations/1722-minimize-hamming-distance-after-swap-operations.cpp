/*

    what we need to do????????????????

    we have to convert source into target array...........

    how???????????

    a graph can be formed:
    where nodes are source 
    and 
    edges will be allowedSwaps

    means connected nodes can be swap directly or indirectlyyyy

    we can foam the groups of connected node
    like 
    {0,1,2,3} can swap directlt or indirectly

    How will you form groups?


*/
class Solution {
public:
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            parent[pb] = pa;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Step 1: Initialize DSU
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Step 2: Build groups
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Step 3: Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int p = find(i);
            groups[p].push_back(i);
        }

        int mismatch = 0;

        // Step 4: Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // Count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // Try matching with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    mismatch++;
                }
            }
        }

        return mismatch;
    }
};
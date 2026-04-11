class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Step 1: Store indices of each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: Process each value group
        for (auto &it : mp) {
            vector<int> &idx = it.second;

            // Need at least 3 occurrences
            if (idx.size() < 3) continue;

            // Step 3: Sliding window of size 3
            for (int i = 0; i + 2 < idx.size(); i++) {
                int a = idx[i];
                int c = idx[i + 2];

                // Optimized distance
                int dist = 2 * (c - a);

                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
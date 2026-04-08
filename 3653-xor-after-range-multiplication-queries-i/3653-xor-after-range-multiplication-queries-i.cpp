class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int MOD = 1e9 + 7;
        for(int i=0;i<queries.size();i++){
            auto it = queries[i];
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            for(int j = l; j <= r; j+=k){
                nums[j] = (1LL * nums[j] * v) % MOD;
            }
        }
        int res = 0;
        for(auto i : nums){
            res ^= i;
        }        
        return res ^ 0;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        long long odd = 0, even = 1;
        long long ans = 0;
        int sum = 0;
        int MOD = 1e9 + 7;

        for(int x : nums) {
            sum += x;

            if(sum % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            }
            else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> nums;
    int n;
    int dp[201][201][201];

    int solve(int idx, int gcd1, int gcd2) {

        if (idx == n) {
            return (gcd1 == gcd2 && gcd1 != 0);
        }

        if (dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2];

        long long ans = 0;

        // 1. Skip current element
        ans += solve(idx + 1, gcd1, gcd2);

        // 2. Put in seq1
        ans += solve(idx + 1, std::gcd(gcd1, nums[idx]), gcd2);

        // 3. Put in seq2
        ans += solve(idx + 1, gcd1, std::gcd(gcd2, nums[idx]));

        return dp[idx][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};
class Solution {
public:
    int n;
    vector<int> v;
    vector<vector<int>> dp;

    int f(int i, int val) {
        if (i == n) {
            return (val == 0) ? 0 : 1e9;
        }

        if (dp[i][val] != -1) return dp[i][val];

        // option 1: don't take this element
        int notTake = f(i + 1, val);

        // option 2: take this element
        int take = 1 + f(i + 1, val ^ v[i]);

        return dp[i][val] = min(take, notTake);
    }

    int minRemovals(vector<int>& a, int target) {
        v = a;
        n = v.size();

        int total_xor = 0;
        for (int x : v) total_xor ^= x;

        int req = total_xor ^ target;

        int mx = 1;
        while (mx <= 10000) mx <<= 1;  // XOR range

        dp.assign(n, vector<int>(mx, -1));

        int ans = f(0, req);

        return (ans >= 1e9) ? -1 : ans;
    }
};
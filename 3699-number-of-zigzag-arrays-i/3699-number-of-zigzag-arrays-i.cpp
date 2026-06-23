/*
    a[i] ∈ [l, r]

    Conditions:
    1. Adjacent elements cannot be equal
            a[i] != a[i-1]

    2. No strictly increasing triple
            a[i-2] < a[i-1] < a[i]

    3. No strictly decreasing triple
            a[i-2] > a[i-1] > a[i]

    ------------------------------------

    Since adjacent elements are never equal,

    Every adjacent pair is either:

            UP      (a[i] > a[i-1])
            DOWN    (a[i] < a[i-1])

    Forbidden:

            UP UP
            DOWN DOWN

    Allowed:

            UP DOWN
            DOWN UP

    Therefore directions must alternate.

    ------------------------------------

    DP State:

    dp[val][dir]

    dir = 0 -> last move was DOWN
    dir = 1 -> last move was UP

    dp[val][dir]
        = number of valid arrays ending at value 'val'
          whose last direction is 'dir'

    ------------------------------------

    Transition:

    If last direction was UP:

            previous value < val

    Next direction must be DOWN.

    Therefore next value must be < val.

    dpNext[x][DOWN] += dp[val][UP]
            for all x < val


    If last direction was DOWN:

            previous value > val

    Next direction must be UP.

    Therefore next value must be > val.

    dpNext[x][UP] += dp[val][DOWN]
            for all x > val

    ------------------------------------

    Brute transition:

            O(n * m²)

    where

            m = r-l+1

    Optimize using prefix sums:

            sum of all values < val
            sum of all values > val

    giving

            O(n * m)

*/
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1e9 + 7;
        r -= l;
        vector<int> dp(r + 1, 1);
        for (int i = 1; i < n; i++) {
            int pre = 0, pre2;
            if (i & 1) {
                for (int v = 0; v <= r; v++) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            } else {
                for (int v = r; v >= 0; v--) {
                    pre2 = pre + dp[v];
                    dp[v] = pre;
                    pre = pre2 % MOD;
                }
            }
        }
        int res = 0;
        for (int v : dp)
            res = (res + v) % MOD;
        return res * 2 % MOD;
    }
};
/*
    we have m * n martrix
        we are intially at (0,0)
        wants to reach (m-1,n-1)
    
    robot can move either right or down at any point in time.

    If coins[i][j] >= 0, the robot gains that many coins
            total += coins[i][j]

    if coins[i][j] < 0, the robber steals the absolute value of coins[i][j] coins
            total -= abs(coins[i][j])

    neutralize robbers in at most 2 cells on its path
        means we have 2 protection points

    return the maximum profit the robot can gain on the route.

    their can be several ways to reach our destination 
        but we need to return which have maximum 

    so we have to try all possible ways

        ------RECUSRION------

    how many possibilitiies???
    (assume we are start from (m-1,n-1))

    left
        OR 
    top

    return left + right

    how many varibales???
        1. index
        2. protection points (2)

    lets dry run and check 

    by doing dry run it make much easy
    int n = row
    int m = col


    left = f(n,m-1,points)
    up = f(n-1,m,points)

    first try to reach destination then while back tracking do the adding thing 

    their are 2 CASE 
        dont use power
            OR
        use power (only if negative cell)

    DONE.........

    use memoization:

    dp size (how many varribales) :

    i -> n-1 to 0
    j -> m-1 to 0
    pp -> 2 to 0

    we can't put -1 in dp 
        what if value is -1
    

*/
class Solution {
public:
    int f(int i, int j, int pp, vector<vector<int>>& coins,vector<vector<vector<int>>>& dp) {
        if(i < 0 || j < 0) return -1e9;

        if(i == 0 && j == 0) {
            if(coins[0][0] >= 0) return coins[0][0];
            else {
                if(pp > 0) return 0;
                else return coins[0][0];
            }
        }

        int best = -1e9;
        
        if(dp[i][j][pp] != -1e9) return dp[i][j][pp];

        // move from left and up
        int left = f(i, j-1, pp, coins,dp);
        int up   = f(i-1, j, pp, coins,dp);

        // CASE 1: don't use power
        best = coins[i][j] + max(left, up);

        // CASE 2: use power (only if negative cell)
        if(coins[i][j] < 0 && pp > 0) {
            int usePower = max(
                f(i, j-1, pp-1, coins,dp),
                f(i-1, j, pp-1, coins,dp)
            );
            best = max(best, usePower);
        }

        return dp[i][j][pp] = best;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        
        const int NEG = -1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, NEG)));
        return f(n-1,m-1,2,coins,dp);
    }
};
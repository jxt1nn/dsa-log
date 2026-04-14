/*
    we can move either left or right........

    sort both the arrays
    robots
    and 
    factory by position..........

    so what am thinking 
        find previous smaller factory 
            AND 
        find next  greatre factory for each robot index.....

then find the distance for each robot 
    left disttance and right distance and take the minimm one 
    and make limit of that factory decrease by 1 



*/
class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        if (i == n) return 0;
        if (j == m) return 1e18;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j + 1, robot, factory); // skip factory

        long long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        for (int k = 1; k <= limit && i + k - 1 < n; k++) {
            cost += abs(robot[i + k - 1] - pos);
            ans = min(ans, cost + solve(i + k, j + 1, robot, factory));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory);
    }
};
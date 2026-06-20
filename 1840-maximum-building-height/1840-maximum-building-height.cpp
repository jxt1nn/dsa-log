class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        
        // Mandatory restrictions
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right pass
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + dist
            );
        }

        // Right -> Left pass
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + dist
            );
        }

        long long ans = 0;

        // Find maximum peak between every adjacent restriction pair
        for (int i = 1; i < m; i++) {

            long long id1 = restrictions[i - 1][0];
            long long h1  = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            long long dist = id2 - id1;

            long long peak = (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};
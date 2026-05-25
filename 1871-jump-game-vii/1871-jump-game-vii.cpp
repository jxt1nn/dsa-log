class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        // IMPORTANT
        // prevents re-scanning old ranges
        int farthest = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            // reached end
            if (i == n - 1)
                return true;

            // range we can explore from i
            int start = max(i + minJump, farthest + 1);
            int end   = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {

                // can stand only on '0'
                if (s[j] == '0' && !visited[j]) {

                    visited[j] = true;
                    q.push(j);
                }
            }

            // update scanned boundary
            farthest = end;
        }

        return false;
    }
};
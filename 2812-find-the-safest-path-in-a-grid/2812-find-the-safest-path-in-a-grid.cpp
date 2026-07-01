/*

    Compute each cell's distance to the nearest thief.

    first add all thievs cells in array 

    then traverse in matrix and if cell is not thief compute it distance to every theif and take 
    minimum from them 

----this wil take too much time 

Starting from the thief, what cells can I reach in 1 step? 2 steps? 3 steps?

    all edges have weight 1
    we want the shortest distance
    and there are multiple starting points

----Multi-Source BFS

Imagine this grid

0 0 0
0 1 0
0 0 0

afetr BFS 

    2 1 2
    1 0 1
    2 1 2

    Higher number = safer
    Lower number = closer to a thief


Treat those distances as each cell's "safety score."

---Find a path that maximizes the minimum safety score encountered along the way.

use Modified Dijkstra


*/
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: Multi-Source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &[dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Modified Dijkstra
        priority_queue<vector<int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            // Reached destination
            if (r == n - 1 && c == n - 1)
                return safe;

            if (safe < best[r][c])
                continue;

            for (auto &[dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    int newSafe = min(safe, dist[nr][nc]);

                    if (newSafe > best[nr][nc]) {
                        best[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};
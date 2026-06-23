/*

    treat elevation as cost of the cell

    We need to reach (n-1,n-1) from (0,0).

    Water level at time t means:
        We can stand only on cells having elevation <= t.

    Instead of thinking about water,
    think about the path.

    For any path:

        path = 0 -> 1 -> 4 -> 7 -> 3

    We cannot use this path until water level reaches:

        max(0,1,4,7,3) = 7

    Therefore,

        Cost of a path =
            maximum elevation present on that path

    We need:

        Path whose maximum elevation is minimum.

    ------------------------------------------------

    Dijkstra Observation:

        dist[r][c]

    = minimum water level required
      to reach cell (r,c)

    = minimum possible maximum elevation
      seen so far.

    ------------------------------------------------

    Normal Dijkstra:

        newCost = dist[node] + weight

    Here:

        newCost = max(
                    dist[r][c],
                    grid[nr][nc]
                 )

    because entering a higher elevation
    may increase the required water level.

    ------------------------------------------------

    Why Dijkstra works?

        max(currentCost , x)
            >= currentCost

    Cost never decreases.

    This monotonic property is exactly
    what Dijkstra needs.

    ------------------------------------------------

    Recognition Pattern:

    If problem says:

        - minimum possible maximum
        - minimize the largest value
        - minimize the worst obstacle
        - minimum threshold to reach end

    Think:

        Dijkstra + max()

*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if(cost > dist[r][c]) continue;

            for(int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                int newCost = max(cost, grid[nr][nc]);

                if(newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr,nc}});
                }
            }
        }

        return dist[n-1][n-1];
    }
};
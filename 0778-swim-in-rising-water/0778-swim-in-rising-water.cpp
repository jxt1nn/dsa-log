/*

    We need to reach (n-1,n-1) from (0,0).

    bullshit question ststement for understanding read this........

    every cell is a city 
    for enter any citty we have  that much money in our pocket
    we dont use any money only we need that money in our pocket to enter

    For any path:

        path = 0 -> 1 -> 4 -> 7 -> 3

    we cannot go 7 city if we dont have 7 rupees in over pocket........


        max(0,1,4,7,3) = 7

    Therefore,

        Cost of a path =
            maximum city price present on that path

    ------------------------------------------------

    this is graph realation problem
    MODIFIED DIJKSTARA

    state : cost
    transition : new = max(curr,cost[v])
    priority : cost (min-heap)
    relaxtion : (new < dist[v])




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
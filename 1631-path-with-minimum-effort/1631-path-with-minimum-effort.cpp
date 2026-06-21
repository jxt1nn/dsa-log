/*
    we have a 2d matrix.......
        we have to go from (0,0) to (n-1,m-1)

    we can move up, down, left, or right, 
        and you wish to find a route that requires the minimum effort

    what is route efforts????????
        maximum absolute difference in heights between two consecutive cells of the route

    return the minimum effort required
        to travel from the top-left cell to the bottom-right cell.

    heights = [ [1,2,2]
                [3,8,2],
                [5,3,5]]

    The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.

    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

    what we need to do?????????

    Cost between two cells = |height1 - height2|

    BFS not  works here bcoz we have differnt value of each cell    

    ----------dikstara algo---------
    
    step of Dijkstra:

    1. priority quque ->  src and dist
       and dist vector -> dist[src] = 0
        pop

    2. then check all its adj
    3. if olddist + edge w < dist[node] 
    4. we push into pq and modify the distance

    now we impiliment dijkstra according to this question......
    
    put src and effort in pq

    what pq store {{row,col},effort}

    effort[src] = 0

    then check all its neighbors
        int dx[4] = {-1,1,0,0}
        int dy[4] = {0,0,-1,1}

    if(inBONDARY)
    int eff = |old - new|


    their  is one more thing
        The maximum absolute difference along the entire path.

    int diff = abs(heights[i][j] - heights[ni][nj]);
    int newEffort = max(currentEffort, diff);

    if (newEffort < effort[ni][nj]) {
        effort[ni][nj] = newEffort;
        pq.push({{ni,nj}, newEffort});
    }

    and if we reach 0,0 and n-1,m-1 ret
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        // Min heap -> {{row, col}, effort}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0,0}});
        effort[0][0] = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int currEffort = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // if reached destination bcoz pq already store it in increasing manner 
            if(x == n-1 && y == m-1)
                return currEffort;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {

                    int diff = abs(heights[x][y] - heights[nx][ny]);

                    // IMPORTANT: take max
                    int newEffort = max(currEffort, diff);

                    if(newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0; // fallback (won't reach here normally)
    }
};
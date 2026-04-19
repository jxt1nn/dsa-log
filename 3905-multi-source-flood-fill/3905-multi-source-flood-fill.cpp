/*
    create a grid of n * m all element currently 0

    then start BFS from source nodes  
    first colour the node 
    then its neighbours

    and if a cell visited multiple time in a single cycle 

    we should resolve the conflit 
    using map

    If multiple colors reach the same uncolored cell
    at the same time step, the cell takes the color with the maximum value.

    At each BFS level:

    Process all nodes of current level
    For next level:
    Collect all candidate spreads
    If multiple reach same cell → keep max color

    grid[n][m] → result
    queue → (row, col, color)
    map or temp grid → to resolve conflicts per level


    BFS

    While queue not empty:
    Take current level size

    Create temporary structure:
    map<pair<int,int>, int> nextColor;

    For all nodes in this level:
        Try 4 directions
        If cell is uncolored:

    store:
    nextColor[{r,c}] = max(existing, new color)

    then:
    After processing level:
        Apply updates to grid
        Push new cells into queue


*/
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> grid(n, vector<int>(m, 0));

        queue<tuple<int,int,int>> q;

        // initialize
        for(auto &s : sources){
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            q.push({r,c,color});
        }

        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        while(!q.empty()){
            int sz = q.size();

            map<pair<int,int>, int> nextColor;

            for(int i = 0; i < sz; i++){
                auto [r,c,color] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        auto key = make_pair(nr,nc);
                        nextColor[key] = max(nextColor[key], color);
                    }
                }
            }

            // apply updates
            for(auto &it : nextColor){
                int r = it.first.first;
                int c = it.first.second;
                int color = it.second;

                grid[r][c] = color;
                q.push({r,c,color});
            }
        }

        return grid;
    }
};
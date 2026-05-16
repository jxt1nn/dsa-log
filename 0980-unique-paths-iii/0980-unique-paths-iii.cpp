/*

    Return the number of 4-directional walks from the 
    starting square to the ending square,
    that walk over every non-obstacle square exactly once.

    basically means,
        return all paths


    choices at each index
        left right , up down

    this is simple bactracking question 
    where we need to reach the destination 

    for(all direction) :

        if(isSafe):
        
            choose
            explore
            backtrack(undo)

    but their is a condition 

    that walk over every non-obstacle square exactly once
    means before reaching destination 
    we need to visit all cells (without obstacls)
        exactly once..........

    how can we do this....?????
    
    1. Count usable cells

    Before DFS, count:
        all cells except -1

    2. During recursion

    Maintain:
        countVisited

    Whenever you enter a cell:
        countVisited++
    and mark visited.

    WHAT IS BASE CASE?????????

    Did I reach destination AFTER visiting all usable cells?
    So destination becomes valid only when:

    If current cell is destination:
        if(countVisited == totalUsableCells)
            found one valid path
        else
            invalid path


    So recursion becomes:

    Explore all 4 directions
    while avoiding:
    - out of bounds
    - obstacles
    - visited cells

    and after recursion:

    unvisit (backtrack)
    countVisited--






*/
class Solution {
public:

    int ans = 0;

    bool isSafe(int row,
                int col,
                vector<vector<int>>& grid,
                vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        // out of bounds
        if(row < 0 || col < 0 || row >= n || col >= m)
            return false;

        // obstacle
        if(grid[row][col] == -1)
            return false;

        // already visited
        if(vis[row][col] == 1)
            return false;

        return true;
    }

    void dfs(vector<vector<int>>& grid,
             int row,
             int col,
             int visitedCount,
             int totalCells,
             vector<vector<int>>& vis) {

        // reached destination
        if(grid[row][col] == 2) {

            // valid path only if all cells visited
            if(visitedCount == totalCells)
                ans++;

            return;
        }

        // directions
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if(isSafe(nr, nc, grid, vis)) {
            
                // mark visited
                vis[row][col] = 1;

                dfs(grid,
                    nr,
                    nc,
                    visitedCount + 1,
                    totalCells,
                    vis);

                // backtrack
                vis[row][col] = 0;
            }
        }

    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int startRow = 0;
        int startCol = 0;

        int totalCells = 0;

        // count non-obstacle cells
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] != -1)
                    totalCells++;

                if(grid[i][j] == 1) {

                    startRow = i;
                    startCol = j;
                }
            }
        }

        vector<vector<int>> vis(n,
                                vector<int>(m, 0));

        vis[startRow][startCol] = 1;
        dfs(grid,
            startRow,
            startCol,
            1,
            totalCells,
            vis);

        return ans;
    }
};
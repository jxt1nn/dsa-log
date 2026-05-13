/*

GOLD MINE PROBLEM — BACKTRACKING + DFS INTUITION
=================================================

we are given a grid:

0 -> blocked cell
>0 -> gold in cell

we can move:
UP, DOWN, LEFT, RIGHT

we CANNOT:
- visit 0 cells
- revisit same cell in one path

we can START from ANY cell with gold


---------------------------------------------
WHAT IS THE QUESTION REALLY ASKING?
---------------------------------------------

we are NOT asked:

"find one path"

we are asked:

"find maximum gold from ANY path"


so it screams:

BACKTRACKING + DFS + MAX OVER ALL PATHS


---------------------------------------------
MAIN INTUITION SHIFT
---------------------------------------------

at every cell we ask:

"if I start from here, what is the best gold I can collect?"


so function becomes:

solve(r, c) = maximum gold starting from (r,c)


---------------------------------------------
CHOICES AT EACH CELL
---------------------------------------------

from (r,c) we have 4 choices:

UP    -> (r-1, c)
DOWN  -> (r+1, c)
LEFT  -> (r, c-1)
RIGHT -> (r, c+1)


BUT only valid if:
- inside grid
- not 0
- not visited


---------------------------------------------
STATE OF RECURSION
---------------------------------------------

solve(row, col, visited)

row     -> current position
col     -> current position
visited -> cells already used in current path


---------------------------------------------
WHY VISITED ARRAY?
---------------------------------------------

because we cannot revisit same cell in same path

otherwise:

infinite loops like:
right -> left -> right -> left ...


---------------------------------------------
BASE CASE
---------------------------------------------

no valid moves from current cell

then return grid[row][col]


OR conceptually:

leaf node in recursion tree


---------------------------------------------
CORE TRANSITION (MOST IMPORTANT)
---------------------------------------------

at each cell:

best = max(
    solve(up),
    solve(down),
    solve(left),
    solve(right)
)

final answer:

grid[row][col] + best


---------------------------------------------
WHY THIS MAX FORM?
---------------------------------------------

because:

each direction gives a different possible path

we want BEST among them


so:

best = max(all recursive results)


---------------------------------------------
WHY YOUR "res += ..." IDEA FAILS
---------------------------------------------

because:

res is shared across recursive paths

but each path is independent

so we should NEVER carry sum manually

instead:

return value from recursion


---------------------------------------------
CHOOSE EXPLORE UNDO
---------------------------------------------

CHOOSE:
    mark visited
    move to next cell

EXPLORE:
    recursive call

UNDO:
    unmark visited


---------------------------------------------
STARTING POINT
---------------------------------------------

we can start from ANY cell:

for every cell:
    if grid[i][j] != 0:
        start DFS


---------------------------------------------
TIME COMPLEXITY INTUITION
---------------------------------------------

worst case:

O(4^(m*n))

BUT grid is small, and pruning happens due to:
- visited constraint
- 0 cells


---------------------------------------------
FINAL INTUITION
---------------------------------------------

this problem is:

"from every gold cell,
try all possible non-repeating paths,
and take maximum sum"


NOT:

"one fixed path"

NOT:

"simple traversal"

BUT:

FULL BACKTRACKING SEARCH


---------------------------------------------
CORE RECURSION FORMULA
---------------------------------------------

solve(r,c) =
    grid[r][c] +
    max(
        solve(all 4 directions)
    )

*/
class Solution {
public:

    int solve(vector<vector<int>>& grid,
              int r,
              int c,
              vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> dr = {1, 0, 0, -1};
        vector<int> dc = {0, -1, 1, 0};

        int best = 0;

        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 &&
               nr < n && nc < m &&
               grid[nr][nc] != 0 &&
               !vis[nr][nc]) {

                vis[nr][nc] = 1;

                best = max(best,
                            solve(grid, nr, nc, vis));

                vis[nr][nc] = 0;
            }
        }

        return grid[r][c] + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] != 0) {

                    vis[i][j] = 1;

                    ans = max(ans,
                              solve(grid, i, j, vis));

                    vis[i][j] = 0;
                }
            }
        }

        return ans;
    }
};
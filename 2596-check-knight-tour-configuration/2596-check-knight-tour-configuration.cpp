/**

we can move 8 moves from current posoiton 

(row-2,col+1)
(row-1,col+2)
(row+1,col+2)
(row+2,col+1)
(row+2,col-1)
(row+1,col-2)
(row-1,col-2)
(row-2,col-1)

THIS ARE THE 8 MOVES CAN KNIGHT MOVES

we are currently at (0,0) index with value 0

and want to reach (n*n-1)

how can we go their............

what are the choices at each inddex 
we have total 8 choices at any index 

and we want to find curr+1 value from each index 
if we can find it we move furture 
if not return false;

*/
class Solution {
public:
    bool solve(vector<vector<int>>& grid,int row,int col,int n,int expected){
        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expected){
            return false;
        }

        if(grid[row][col] == n*n-1){
            return true;
        }

        bool ans1 = solve(grid, row-2, col+1, n,expected+1);

        bool ans2 = solve(grid, row-1, col+2, n,expected+1);

        bool ans3 = solve(grid, row+1, col+2, n,expected+1);

        bool ans4 = solve(grid, row+2, col+1, n,expected+1);

        bool ans5 = solve(grid, row+2, col-1, n,expected+1);

        bool ans6 = solve(grid, row+1, col-2, n,expected+1);

        bool ans7 = solve(grid, row-1, col-2, n,expected+1);

        bool ans8 = solve(grid, row-2, col-1, n,expected+1);

        return ans1 || ans2 || ans3 || ans4 ||
                ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid,0,0,n,0);
    }
};
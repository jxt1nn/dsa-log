/*

    Write a program to solve a Sudoku puzzle by filling the empty cells.

what are the rules :

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

we cannot solve this directly 
we have to make answer gradully 

try a number and go deeper 
and when it fails we backtrack 

what are the choics for each cell?????
    (1-9)


then check choice is safe or not........

means :
    -> that number should not be presnt in that row 
    column 
    and grid

if it is safe 
add that number to that cell 
grid[i][j] = number

go deeper:
 solve()

backtrcak:
    grid[i][j] = "."

this is the whole logic 

we start from 1st row and try to fill......

    solve(board)

    base case :
    if(row == 9)
        return true;

    int newRow = row;
    int newCol = col+1;

        if(newCol == 9){
            newRow = row+1;
            newCol = 0;
        }

    Try numbers 1 → 9

        if safe:

            place number

            if solve(board):
                return true

            undo placement

    If nothing works:
        return false
 


    how to write isSafe fucntion:

    col check
    row check 

    
We need to check the current 3x3 box.

For any cell (row, col),
we must find:

    top-left starting cell of its box


Sudoku boxes start from:

    (0,0)  (0,3)  (0,6)

    (3,0)  (3,3)  (3,6)

    (6,0)  (6,3)  (6,6)


Notice:

    every box starts at multiples of 3


-----------------------------------
HOW THIS WORKS
-----------------------------------

Suppose:

    row = 5
    col = 7


STEP 1:

    row / 3

    5 / 3 = 1

This tells:

    current row belongs to box-group 1

Groups are:

    rows 0-2 -> group 0
    rows 3-5 -> group 1
    rows 6-8 -> group 2


STEP 2:

    (row / 3) * 3

    1 * 3 = 3

So starting row becomes:

    3


Same for column:

    col / 3

    7 / 3 = 2

    2 * 3 = 6

So starting col becomes:

    6


Final answer:

    cell (5,7)

belongs to box starting from:

    (3,6)


That box is:

    (3,6) (3,7) (3,8)

    (4,6) (4,7) (4,8)

    (5,6) (5,7) (5,8)


-----------------------------------
FORMULA
-----------------------------------

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;


Division tells:

    WHICH box

Multiplication tells:

    STARTING index of that box


    3*3 grid check

     for(int i = startRow ; i < startRow+3;i++){
        for(int j =startCol; j < startCol+3;j++){
*/
class Solution {
public:
    bool isSafe(int row,int col,char digit,vector<vector<char>>& board){

        //row check
        for(int i=0;i < 9;i++){
            if(board[row][i] == digit){
                return false;
            }
        }

        //col check
        for(int i=0; i <9;i++){
            if(board[i][col] == digit){
                return false;
            }
        }

        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;

        // 3*3 grid check

        for(int i = startRow ; i < startRow+3;i++){
            for(int j =startCol; j < startCol+3;j++){
                if(board[i][j] == digit){
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(int row,int col,vector<vector<char>>& board){
        if(row == 9){
            return true;
        }
        int newRow = row;
        int newCol = col+1;

        if(newCol == 9){
            newRow = row+1;
            newCol = 0;
        }

        if(board[row][col] != '.'){
            return solve(newRow,newCol,board);
        }

        for(int i ='1'; i <= '9';i++){
            
            if(isSafe(row,col,i,board)){
                
                board[row][col] = i;

                if(solve(newRow,newCol,board)){
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(0,0,board);
    }
};
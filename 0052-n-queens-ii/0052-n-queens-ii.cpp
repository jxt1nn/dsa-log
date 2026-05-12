/*

we have to place n queens on a n*n chess board 

such that no queen attack each other


how queen attack?????????????

queen can attack:

1. same row
2. same column
3. diagonals


can we place more than one queen in a row???????????

NOOOOOOOOO

because they attack each other


SO THE REAL QUESTION BECOMES?????????????

how to place ONE queen
in EVERY row safely


return all distinct solutions

SCREAMS BACKTRACKING..............


what is the main recursion thinking?????????????

At every row ask:

"which column should contain current row queen?"


THAT generates recursion tree



we have n*n board

and we need to place n queens


what are the choices for one queen?????????????

we can place it in ANY column
of current row

BUTTTTTTTTT

position should be SAFE


means:

no other queen can attack us



IMPORTANT OBSERVATION?????????????

we place queens ROW BY ROW

so:

row0 queen
then row1 queen
then row2 queen
...

means current row is always empty initially


THAT IS WHY:

we don't need to check current row

because we place only ONE queen per row



what are the states of recursion?????????????


solve(row)


why only row?????????????

because:

if row = 0
means 0 queens placed

if row = 1
means 1 queen already placed

if row = 2
means 2 queens already placed


so row itself tells
how many queens are already placed


NO NEED:

solve(row,queenCount)



what are the choices?????????????


for(int col = 0; col < n; col++){

    if(validPosition){

        choose

        explore

        backtrack
    }
}



what is the base case?????????????


if(row == n){

    store current board

    return
}


why?????????????

because:

we successfully placed queens
in all rows



how to represent board?????????????


vector<string> board(n, string(n,'.'));


example for n = 4


....
....
....
....



when placing queen?????????????


board[row][col] = 'Q';


example:


.Q..
....
....
....



after backtracking?????????????


board[row][col] = '.';


VERY IMPORTANT:

we UNDO current choice
so other possibilities can be explored



what is validPosition function?????????????


we need to check:

1. same column
2. left upper diagonal
3. right upper diagonal


IMPORTANT:

NO NEED TO CHECK BELOW

because recursion builds answer gradually

future rows are still empty



how to check column?????????????


for(int i = 0; i < row; i++){

    if(board[i][col] == 'Q'){
        return false;
    }
}


IMPORTANT:

only check ABOVE current row

not whole matrix



how to check LEFT diagonal?????????????


example:

current cell = (2,2)

left upper diagonal cells:

(1,1)
(0,0)


pattern?????????????

(row-1,col-1)


code:


int x = row;
int y = col;

while(x >= 0 && y >= 0){

    if(board[x][y] == 'Q'){
        return false;
    }

    x--;
    y--;
}



how to check RIGHT diagonal?????????????


example:

current cell = (2,2)

right upper diagonal:

(1,3)


pattern?????????????

(row-1,col+1)


code:


x = row;
y = col;

while(x >= 0 && y < n){

    if(board[x][y] == 'Q'){
        return false;
    }

    x--;
    y++;
}



if all checks pass?????????????


return true;



what is choose explore backtrack?????????????


CHOOSE:

board[row][col] = 'Q';


EXPLORE:

solve(row+1);


BACKTRACK:

board[row][col] = '.';



WHY BACKTRACKING?????????????


because current queen placement
may fail later


example:

queen at row0 col0

later maybe no safe position exists
for row3


SO:

undo old queen placement

and try another column



THIS IS BACKTRACKING................



DRY RUN IDEA?????????????


n = 4


row = 0

choices:

place queen at:

(0,0)
(0,1)
(0,2)
(0,3)


suppose:

place at (0,1)


board:


.Q..
....
....
....


now solve(row+1)


row = 1

try every column

skip unsafe columns

place queen on safe column


continue recursively



MOST IMPORTANT INTUITION?????????????


THIS PROBLEM IS NOT:

"fill matrix"


THIS PROBLEM IS:

"choose safe column for every row"


Every recursive level asks:

"which column should contain current row queen?"


THAT SINGLE QUESTION
GENERATES ENTIRE SOLUTION



TIME COMPLEXITY?????????????

roughly:

O(N!)

because:

first row -> n choices
second row -> n-1 choices
third row -> n-2 choices
...


*/
class Solution {
public:

    int ans = 0;

    // check if current position is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {

        // check upper column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // check left diagonal
        int x = row;
        int y = col;

        while(x >= 0 && y >= 0) {

            if(board[x][y] == 'Q') {
                return false;
            }

            x--;
            y--;
        }

        // check right diagonal
        x = row;
        y = col;

        while(x >= 0 && y < n) {

            if(board[x][y] == 'Q') {
                return false;
            }

            x--;
            y++;
        }

        return true;
    }

    void solve(int row,
               vector<string>& board,
               int n) {

        // all queens placed
        if(row == n) {
            ans += 1;
            return;
        }

        // try every column
        for(int col = 0; col < n; col++) {

            // valid position
            if(isSafe(row, col, board, n)) {

                // choose
                board[row][col] = 'Q';

                // explore next row
                solve(row + 1, board, n);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};
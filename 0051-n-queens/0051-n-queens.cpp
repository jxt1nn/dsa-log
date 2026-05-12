/*
we have to place n queens on a n*n chess board 

such no queen attack each other 

cna we place more than one queen in a row????????
NOOOOOOOOO 

bocz ttheyv attcak each other 

so what is the wuestion now 
how to place n queens in n rows 

return all distinct solutions to the n-queens puzzle
    scream BACKTACKING.........

LETS ASSUME, 

we have a n * n

and we have to place n queens

what are the choics for 1 queen???

we can place it on any index of queen row
BUT it should be safe index 
means no oyther queen can attak us

so what are the states of recursion?????????

solve(row,numberOfQueen)

what are the choice we have 

for(int i = 0;i < n;i++)

if(valid){
    choose 
    explore 
    backtrack 
}


what is the abse case?

if(row == n && queen == 0){
    store 
    return
}


lets dry run..........

write  the loop.......

for(int i = 0;i < n;i++){
    if(validPosition(i)){
        m[row][i] = "Q"

        solve(row+1,queen-1);

        m[row][i] = "."

    }
}



we have to write the validPosition fuction...

what are we do n that function........

1. check if already any queen present in this column 

2. check if its upper digoanls conatin any queen

IMPORTANT 

no need to check below bcoz we make answer gradually 

how to check column????????

for(int i =0;i < n;i++){
    if(m[i][col] == 'Q'){
        return false;
    }
}


how to check both the dignoal???????????

left digonal.......

for example n is 4

and we are on (2,2)
left digoanls of (2,2) are

(1,1) (0,0)

means at ever step
(row-1,col-1)

and some where the hit the boundary of the matrix 
and that the end

int x  = row
int y = col


while(x >= 0 && y >= 0){
    if((x,y) == "Q"){
        return false;
    }
    x--;
    y--;
}

now check right digoanls

wht happens in right dihgonals


for example n is 4

and we are on (2,2)
left digoanls of (2,2) are

(1,3) 

means at ever step

(row-1,col+1)

at the end of the function return true;




*/
class Solution {
public:

    vector<vector<string>> ans;

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
            ans.push_back(board);
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

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};
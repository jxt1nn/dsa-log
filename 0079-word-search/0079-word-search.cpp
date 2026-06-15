/*

    we have a m  *  n matrix

    and we have to find string s is present in grid or not????

    The word can be constructed from letters of sequentially adjacent cells,
    where adjacent cells are horizontally or vertically neighboring.

    means we can move 
    LEFT
    UP 
    RIGHT 
    DOWN    
        from our current possition 

    The same letter cell may not be used more than once.
        means we have to make track of visited cells    

    how to find the word???????????

    their can be multiple starting points   
        their can be multiple choics at each step

    choics can be bad 
    so we have to undo them............

    BACKTRACKING....................

    what should we check before moving to next cell????????

    if(inBOUNDARY && notVISITED)

        when we enter the cell what should we check?????????
    is this our desire cell????????????????

    if this is the cell we wanted 
        we move forward otherwise go back 

    what is global base case??????
        if(index == word.size())
            return true;

    


*/
class Solution {
public:
    vector<int> dr = {1, 0, 0, -1};
    vector<int> dc = {0, -1, 1, 0};

    bool solve(vector<vector<char>>& grid, string word,int idx,vector<vector<int>>& vis,int r,int c){


        //local base case
        if(grid[r][c] != word[idx]){
            return false;
        }

        //global base case
        if(idx == word.size()-1){
            return true;
        }

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 &&
               nr < n && nc < m &&
               !vis[nr][nc]) {

                vis[nr][nc] = 1;

                if(solve(grid,word,idx+1,vis,nr,nc)){
                    return true;
                }
                
                vis[nr][nc] = 0;
            }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){

                vis[i][j] = 1 ;

                if(solve(board,word,0,vis,i,j)){
                    return true;
                }

                vis[i][j] = 0;
            }
        }
        return false;
    }
};
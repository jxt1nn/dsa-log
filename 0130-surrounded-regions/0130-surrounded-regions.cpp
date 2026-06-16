/*
    we have a n * m matrix 
        only with 'X' and 'O'

    What is a "Region"?
        All 'O' cells that are connected up, down, left, right.

    What does "Surrounded" mean?
        A region is surrounded if:
        
        NONE of its 'O' cells touch the border (edge) of the matrix
    
    ->>>>>>If even ONE 'O' touches the border → that whole region is SAFE.
        very crucial line 

    its mean if we have some O in matrix and any of the 'O' that connnected to this matrix 
        by left right down up 
    on any border  
        
    we cannot chnage them......they are SAFE..........
    
    What is the task?
        Convert all surrounded 'O' regions into 'X'.
    Do NOT change 'O' regions connected to the border.

                X X X X
                X O O X
                X X O X
                X O X X

    The middle 'O' group → does NOT touch border
        This region is surrounded
        Convert to 'X'
    
    The bottom 'O' → touches border
        DO NOT change it

    so what we can do?????????

    Find all 'O' connected to the border 
        Mark them as SAFE
        and 
        Convert all other 'O' into 'X'

    Step 1: Initialize
        Queue → store all the border 'O'
            first and last row
                and 
            first and last column 

    
    Step 2: BFS (what we do with this)(mark the safe region in vis vector)
        While queue not empty:

            check neigbours :  {1,0}, {-1,0}, {0,1}, {0,-1}
        
        if(inBoundary and vis[nx][ny] == 0 && mat[nx][ny] = 'O'){
            mark as visited 
                and 
            push it into queue
        }
    
    Step 3: Make changes
        find all the index
            where vis[i][j] == 0 && mat[i][j] = "O"

        and change it to "X"

    return nothing bcoz we do in-place changes 
*/
class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        queue<pair<int,int>> q; 
        
        // Step 1: Push all border 'O' into queue   
        //Traverse Top & Bottom Row
        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = 1;
            }
            
            if(mat[n-1][j] == 'O') {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        //Traverse Left & Right Column
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            
            if(mat[i][m-1] == 'O') {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, +1, 0, -1}; 
        
        // Step 2: BFS
        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();

            for(int i =0;i < 4;i++){
                int nx = x + drow[i];
                int ny = y + dcol[i];

                if(nx >= 0 && ny >=0 && nx < n && ny < m 
                && vis[nx][ny] == 0 && mat[nx][ny] == 'O'){
                    vis[nx][ny] = 1; // mark the safe region
                    q.push({nx,ny});
                }
            }
        }
        
        //change those 'O' which is not lying in safe region
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && vis[i][j] != 1){
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
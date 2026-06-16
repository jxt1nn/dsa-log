/*
    we have a n * m grid 
        and 0 represents sea water and 1 is land 

    we have to return the number of land cells in grid for which we cannot walk off 

    when we cannot walk off??

    when all the four side of a land enclosed by water 

    if atleast 1 side is connecting through the border we can walk from it.......

    SO, how can we get that number??????????

    we can mark all the land we can walk off as SAFE

    and whatever remians we count them and return 

    how to maark SAFE???

    BFS.......
        need source location 
            border 1 (first_row,last_row,first_col,last_col)

    Step 1: Initialize
        Queue → store all the border '1'
            first and last row
                and 
            first and last column 

    
    Step 2: BFS (what we do with this)(mark the safe region in vis vector)
        While queue not empty:

            check neigbours :  {1,0}, {-1,0}, {0,1}, {0,-1}
        
        if(inBoundary and vis[nx][ny] == 0 && mat[nx][ny] = '1'){
            mark as visited 
                and 
            push it into queue
        }
    
    Step 3: Count NON-SAFE
        find all the index
            where vis[i][j] == 0 && mat[i][j] = "1"

        and count++


    DONE.......
        but i tried DFS version of this............


    we know for BFS we need source location for start it 

        same goes for dfs 

    in BFS we store the source location in queue 
        then process them 

    but in DFS we found a source location immdeatially start dfs from it 

    in BFS we pop queue front
        but in DFS we just send the x,y

    all direction loop is exactly same
        when ever we need to push it into queue 
            we start dfs from it immediately 
*/
class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        vis[x][y] = 1;

        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, +1, 0, -1}; 

        for(int i= 0; i < 4 ;i++){
            int nx = x + drow[i];
            int ny = y + dcol[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m
                && vis[nx][ny] == 0 && mat[nx][ny] == 1){
                    dfs(nx,ny,vis,mat);
            } 
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        //Traverse Top & Bottom Row
        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 1) {
                dfs(0,j,vis,mat);
            }
            
            if(mat[n-1][j] == 1) {
                dfs(n-1,j,vis,mat);
            }
        }

        //Traverse Left & Right Column
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 1) {
                dfs(i,0,vis,mat);
            }
            
            if(mat[i][m-1] == 1) {
                dfs(i,m-1,vis,mat);
            }
        }
        
        int count = 0;
        for(int i =0;i < n;i++){
            for(int j= 0; j < m;j++){
                if(vis[i][j] == 0 && mat[i][j] == 1){
                    count++;
                }   
            }
        }
        return count;
    }
};
// class Solution {
// public:
//     int numEnclaves(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();

//         vector<vector<int>> vis(n,vector<int> (m,0));

//         queue<pair<int,int>> q;

//         // Step 1: Push all border '1' into queue   
//         //Traverse Top & Bottom Row
//         for(int j = 0; j < m; j++) {
//             if(mat[0][j] == 1) {
//                 q.push({0, j});
//                 vis[0][j] = 1;
//             }
            
//             if(mat[n-1][j] == 1) {
//                 q.push({n-1, j});
//                 vis[n-1][j] = 1;
//             }
//         }

//         //Traverse Left & Right Column
//         for(int i = 0; i < n; i++) {
//             if(mat[i][0] == 1) {
//                 q.push({i, 0});
//                 vis[i][0] = 1;
//             }
            
//             if(mat[i][m-1] == 1) {
//                 q.push({i, m-1});
//                 vis[i][m-1] = 1;
//             }
//         }

//         int drow[] = {-1, 0, +1, 0}; 
//         int dcol[] = {0, +1, 0, -1}; 
        

//         while(!q.empty()){
//             auto[x,y] = q.front();
//             q.pop();

//             for(int i = 0;i < 4;i++){
//                 int nx = x + drow[i];
//                 int ny = y + dcol[i];

//                 if(nx >= 0 && ny >= 0 && nx < n && ny < m
//                 && vis[nx][ny] == 0 && mat[nx][ny] == 1){
//                     vis[nx][ny] = 1;
//                     q.push({nx,ny});
//                 }  
//             }
//         }
//         int count = 0;
//         for(int i =0;i < n;i++){
//             for(int j= 0; j < m;j++){
//                 if(vis[i][j] == 0 && mat[i][j] == 1){
//                     count++;
//                 }   
//             }
//         }
//         return count;
//     }
// };
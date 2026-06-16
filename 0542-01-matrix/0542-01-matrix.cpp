/*
    we have a n * m matrix 
        and we need to find the distance of nearest 0 from 1 present in matrix 


    WE LEARN VERY IMPPORANT THING TODAY..........

    FOR BFS :
        WE NEED SOURCE LOCATION (where we start our bfs)

    SO,
        we store all zeros location in queue

    QUEUE : {{sr,sc},distance}
        distance intially start from 0 when we store all zeros location.......

    then we do BFS from this store locations
        in all four directions :

        {1,0}, {-1,0}, {0,1}, {0,-1}

    Step 1: Initialize
        Queue → store all zeros loction with distance 0

    Step 2: BFS
        While queue not empty:
        Process all store locations
            (store the distance value in result martix)
        
        check neighbours..{1,0}, {-1,0}, {0,1}, {0,-1}

            if(inBoundary && vis[nx][ny] == 0){
                push into queue (with distance + 1)
                mark as visted in array 
                
            }
 

*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> dist(n, vector<int>(m, 0)); 
        
        queue<pair<pair<int,int>, int>> q; 
        
        // Step 1: Push all 0s into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0}); 
                    vis[i][j] = 1; 
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0}; 
        int delcol[] = {0, +1, 0, -1}; 
        
        // Step 2: BFS
        while(!q.empty()) {
            int row = q.front().first.first; 
            int col = q.front().first.second; 
            int steps = q.front().second; 
            q.pop(); 
            
            dist[row][col] = steps; 
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                
                if(nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0) 
                {
                    vis[nrow][ncol] = 1; 
                    q.push({{nrow, ncol}, steps + 1});  
                }
            }
        }
        
        return dist; 
    }
};
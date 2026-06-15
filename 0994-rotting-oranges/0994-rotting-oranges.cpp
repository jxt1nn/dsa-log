/*
    we have a m * n matrix

    matrix[i] can have 3 values : 

        0 representing an empty cell,
        1 representing a fresh orange
        2 representing a rotten orange

    Every minute, any fresh orange that is 4-directionally 
        adjacent to a rotten orange becomes rotten

    means if we have 3 * 3 matrix
        and [1][1] will be rotten so in next one minute 
        
        [i-1][j]  [i+1][j]  [i][j-1]  [i][j+1] will became rotten........

    i understand the logic but i don't know how to link this from graph (BFS or DFS)...

    here is a important info........
        if we have 2 rotten orange both work on a single time....

    show what will we do find the 
        already present in matrix and put them into q with time 0

    SO, 
        then, start bfs from this rotten oranges present in queue

        why BFS???not dfs?????

    bcoz we can move in 4 direction at a time with dfs this is not possible

    SO,
        we can move 4 directions 
            [i-1][j]  [i+1][j]  [i][j-1]  [i][j+1] 
    
    Directions :    
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

    and what is the vaild check before moving to a cell 

    if(visited[i][j] != 2 && mat[i][j] == 1 && also check they are not out of bound){
        mark visted 
        put it into queue
    }

    Step 1: Initialize
        Queue → store rotten oranges
        Count fresh oranges

    Step 2: BFS
        While queue not empty:
        Process all current rotten oranges
        Rot neighbors
        Decrease fresh count
        Increase minute
 
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: collect rotten & count fresh
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        int minutes = 0;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        // Step 2: BFS
        while(!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for(int i = 0; i < size; i++) {
                auto [x,y] = q.front();
                q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m 
                       && grid[nx][ny] == 1) {
                        
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            
            if(rotted) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};

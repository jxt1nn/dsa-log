/*

    we have a grid 
    and we have to go (n-1,m-1)
    from (0,0)

    we can go left up down right from any cell if it is inBoundary

    if we step on a cell with 1 our health reduce by 1

    and we have to rach our destination with 1 or more health points
    
    we cannot gain any health points 

    when ever our health became < 1 this path is invailid.......

    state : health remaining at each cell
    transtion : new = curr - nei
    priority : high health -> maxHeap
    relaxtion : newhealth > oldHealth

    one more thing if (0,0) is 1 our health get reduce 


    code intiution :

    bestHealth[][]

    maxHeap

    push(startHealth, 0, 0)

    while(!pq.empty()){

        pop()

        if(destination)
            return true;

        for(4 directions){

            if(outside)
                continue;

            newHealth = ?

            if(newHealth < 1)
                continue;

            if(newHealth > bestHealth[nr][nc]){

                update

                push(...)
            }
        }
    }

    return false;
*/
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int startHealth = health - grid[0][0];
        if(startHealth < 1)
            return false;

        vector<vector<int>> bestHealth(m, vector<int>(n, -1));
        priority_queue<tuple<int,int,int>> pq;

        bestHealth[0][0] = startHealth;
        pq.push({startHealth, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto [currHealth, r, c] = pq.top();
            pq.pop();

            if(r == m-1 && c == n-1)
                return true;

            if(currHealth < bestHealth[r][c])
                continue;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                
                int newHealth = currHealth - grid[nr][nc];

                if(newHealth < 1)
                    continue;

                if(newHealth > bestHealth[nr][nc]){
                    bestHealth[nr][nc] = newHealth;
                    pq.push({newHealth,nr,nc});
                }
            }
        }
        return false;
    }
};
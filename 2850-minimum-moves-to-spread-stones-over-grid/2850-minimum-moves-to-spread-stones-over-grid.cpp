/*
    we have a matrix 3*3
    and total 9 stones

    each cell should contain 1 stone 
    some cells contain more than 1 stones 

    we need to pick stone from that cells and move to cell which contain 0

    can we store the count of each cell
    how many stones they contain intially

    IMPORTANT GRID IS 3 * 3 only

    so we check for each cell which contain 0
    is any cell in their row or colum contain more than one 1 stone if yes we pick it 

    So movement cost between two cells is:

    Manhattan Distance
    (r1,c1) -> (r2,c2)     
    because each move changes row or column by 1.
    
    Convert grid into:

    extra stones list
    empty cells list

    Then:
    match extras -> empties
    minimum total Manhattan distance


*/
class Solution {
public:

    vector<pair<int,int>> emptyCells;
    vector<pair<int,int>> extraStones;

    int solve(int index) {

        // all empty cells filled
        if(index == emptyCells.size()) {
            return 0;
        }

        int ans = 1e9;

        auto [er, ec] = emptyCells[index];

        // try every extra stone
        for(int i = 0; i < extraStones.size(); i++) {

            auto [sr, sc] = extraStones[i];

            // already used
            if(sr == -1) continue;

            // distance
            int dist = abs(er - sr) + abs(ec - sc);

            // mark used
            extraStones[i] = {-1, -1};

            ans = min(ans, dist + solve(index + 1));

            // backtrack
            extraStones[i] = {sr, sc};
        }

        return ans;
    }

    int minimumMoves(vector<vector<int>>& grid) {

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                // empty cell
                if(grid[i][j] == 0) {
                    emptyCells.push_back({i,j});
                }

                // extra stones
                else if(grid[i][j] > 1) {

                    int extra = grid[i][j] - 1;

                    while(extra--) {
                        extraStones.push_back({i,j});
                    }
                }
            }
        }

        return solve(0);
    }
};
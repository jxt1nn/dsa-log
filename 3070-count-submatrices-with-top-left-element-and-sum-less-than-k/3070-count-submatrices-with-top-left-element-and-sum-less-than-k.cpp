/*
    we have a grid and a integer K 

    Return the number of submatrices that contain the top-left element of the grid
    , and have a sum less than or equal to k.

 
    means [0,0] should be always inculed in submatrix

    SO first thought is
        make a prefix matrix 

    where at every i :
       prefix[i][j] = grid[i][j] 
             + prefix[i-1][j] 
             + prefix[i][j-1] 
             - prefix[i-1][j-1]

    prefix[i-1][j-1] : why this..........

    bcoz,

    +---------+-----+
    |         |     |
    |   A     |  B  |
    |         |     |
    +---------+-----+
    |         |     |
    |   C     |  D  |
    |         |     |
    +---------+-----+

    We are calculating for D = (i,j)

    prefix[i-1][j] → covers A + B
    prefix[i][j-1] → covers A + C

    👉 So region A is counted twice ❗

    Subtract the overlap region..........

    “Top + Left counts common area twice → subtract it once”

    should care full about boundary checks (i > 0)(j > 0)

        now our prefix matrix ready now 
    traverse in this and count indexs where sum <= K 

    and return the answer 

*/
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                prefix[i][j] = grid[i][j];

                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];

                if(prefix[i][j] <= k) count++;
            }
        }

        return count;
    }
};
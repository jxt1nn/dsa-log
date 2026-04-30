/*
we have to go form (0,0) to (m-1,n-1)

we have 2 possivilitues on each step :
either right 
    OR
down

we have only 3 integer presnt in grid........
0,1,2

Each cell contributes a specific score and incurs an associated cost:

0: adds 0 to your score and costs 0.
1: adds 1 to your score and costs 1.
2: adds 2 to your score and costs 1. ​​​​​​​


we have a integer K 
we can use only K cost to reach over destination.......

if if exceeds it,the path is  invalid............

we have to return maximum score achievable without exceeding a total cost of K

thier can be multiple path 
    we have to choose the maximum one...........

WE HAVE TO  TRY ALL POSSIBLITIES........

-----------RECURSION------------

what are the possibiilities?
BOTTOM UP:

left OR up

how ee calculate the answer????????
we have to take the maximum...????????????

in take not take case
    we add 1 in take then recursion

but in this we take on every step
either 0 OR 1 OR 2  

but how do we know this time we have to add 0 or when add 1 and 2  

we can make 3 choices in each recursion before calling it


// left:
//     if(0)
//     0 + solve
//     else if(1)
//     1 + solve
//     else
//     2 + solve

// same goes for up also.........


what are the base case????????

1. BoundaryCheck 
2. cost exceeds K
3. reach the destination


BoundaryCheck :
    return -∞


cost exceeds K:
     cost exceeds K → return 0
    🚫 This is dangerous.
    Why?
    Because returning 0 means:
        “this is a valid path with 0 score”

    But actually:
        it is inv
        
    Instead of 0, return:
        -∞ (or a very small number like -1e9)


reach the destination : (0,0)

    if remaining_k >= cost:
        return score
    else:
        return -∞

       -------------I AM SO DUMB-------------- 

we do NOT choose between 0,1,2.

The value (0/1/2) is already fixed in the grid.
grid decides it
we only choices are:

move left (i,j-1)
move up (i-1,j)

“At every cell, I already know its score & cost.
I just need to decide which direction gives me maximum score without exceeding k.”


recursion:

    solve(i, j, remaining_k)

At cell (i, j):

    Take its:
        score
        cost
    If remaining_k < cost:
        → ❌ invalid → return -∞
    Otherwise:
        score + go left
        score + go up
    Return:
        grid_score + max(left, up)

TLE--------------------------

lets add memoixation

varibles chnaging 

i -> m to 0
j -> n to 0
k -> k to 0





*/

class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<int>>& grid) {
        // Out of bounds
        if (i < 0 || j < 0) return INT_MIN;

        int val = grid[i][j];
        int cost = (val == 0 ? 0 : 1);

        //not enough cost
        if (k < cost) return INT_MIN;

        // reach destination
        if (i == 0 && j == 0) {
            return val;
        }

         // ✅ Check memo
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int left = val + solve(i, j - 1, k - cost, grid); // left      
        int up = val + solve(i - 1, j, k - cost, grid); //up

        return dp[i][j][k] = max(left,up);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = solve(m - 1, n - 1, k, grid);
        return (ans < 0 ? -1 : ans);
    }
};
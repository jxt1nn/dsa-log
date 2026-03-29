/*
    we have array and a target
        we need to make this target by adding 
        array elements 

    we use any number of time to make  target 

    we have to return the minimum numbers of elemnts
    to make up the target 

    how can we make a number ???

    coins = [1,2,5], amount = 11

    lets try greddy......
    11 / 5 = 2 numbers 
    1 / 2 can possible 
    1 / 1 = 1 time answer is 3 

    another example [1, 6, 7, 9, 11] , amount = 13
     11 + 1 + 1 answer 3 
        but 6 + 7 answer is 2 
    non-uniformity......

    we havev to try all possible ways and select the minimum one
        
        --RECURSION--

    we have 2 choices either take or not take

    THERE IS A TRCIK IN THIS TYPE OF QUESTION 
        WHEN WE PICK AN ELEMENT WE DONT MOVE FURTHER 

        USE SAME ELEMENT AGAIN AND AGIAN
            UNTILL CONDITION GOT  REJECTED AND NO OTHER OPTION 
            LEFT INSTEAD OF MOVING  

    so 
    what are the base cases ??

    if(i == 0){
        if(target % nums[i] == 0) return target % nums[i];
        else INT_MaX;
    }
    not pick = solve(i-1,target)
    if ( condition )
        pick = solve(i,target - nums[i]) -> same index itrate again and again 

    return min(pick,not pick)

    DONE lets memoixation 

    overlapping subproblems 

    vector size ??????????

    i -> 0 to n-1
        t -> t+1 to 0

    DONE........

    next tabulation.........

    base case????

     on index 0 their can be anything target from 0 to t 
        so we have to fill all dp[0][t]

        if(t % nums[0] == 0) dp[0][t] = t / nums[0];
        else dp[0][t] = INT_MAX;

    loops??

    i = 0 to n-1
    j = 0 to t+1
*/
class Solution {
public:
    int solve(int i,int t,vector<int>& nums,vector<vector<int>>& dp){
        if(i==0){
            if(t % nums[i] == 0) return t / nums[i];
            else return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int notPick = solve(i-1,t,nums,dp);
        int pick = INT_MAX;
        if(nums[i] <= t){
            pick = 1 + solve(i,t-nums[i],nums,dp);
        }
        return dp[i][t] = min(notPick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1,amount,coins,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
// tabulation 

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         const int INF = 1e9;

//         vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

//         // Base case initialization (i == 0)
//         for (int t = 0; t <= amount; t++) {
//             if (t % coins[0] == 0)
//                 dp[0][t] = t / coins[0];
//         }

//         // Fill DP table
//         for (int i = 1; i < n; i++) {
//             for (int t = 0; t <= amount; t++) {

//                 int notPick = dp[i - 1][t];
//                 int pick = INF;

//                 if (coins[i] <= t)
//                     pick = 1 + dp[i][t - coins[i]];

//                 dp[i][t] = min(notPick, pick);
//             }
//         }

//         int ans = dp[n - 1][amount];
//         return (ans >= INF) ? -1 : ans;
//     }
// };


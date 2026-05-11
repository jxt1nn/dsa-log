/*
    we have to return true if we can partiition the 
        array into two subsets 
            both subset sum equal ( true )
        else, (false)

    subset1 + subset2 = S (subset1 == subset2)
    subset = S/2
    so we can say that we have to find the subset of sum S/2

        if we successfully finds it means other one is also exist 

    when we cannot do the partiiton ??
        when total sum of the array is ODD
        (17 / 2 = 8) which is not correct 

    other one is  when we check for a subset and we failed to find it 
         
    first we find the total sum  of the array 
        if its ODD -> false 
        else, check of (total_sum / 2)

    if we find a subsequence of target = total_sum / 2
        return true
    else , return false

    how to find subsequence with target 
    solve(i, target)

        if(target become 0) return true
        if (i < 0) return false

        if(i == 0) return (nums[0] == target) ;

        their is 2 possibilties on each index 
            either take or not take 

        how can we take a element 
        not take = false 

        notpick = solve(i - 1, target)

        take = false;

        if( nums < =target ){
            pick = solve(i-1,target - nums[i])
        }

        return take || notTake

        we some overllaping sub problem 

        lets use memoization 

        size of dp???
        what parameter changing...

        index  from n-1 to 0
        target from target to 0

        if (dp[i][target] != -1)
            return dp[i][target]

        return dp[i][target] = (take || notTake)

        DONE.............

    lets try to convert this into tabulation !!!!!!!!!

    if(target ==0) what can be possible vaules of i??
        0 to n-1

    lets make the loops :

    2 parametre changing
    i = 0 to n-1
    1 to target 




*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: sum = 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: first element
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {

                bool notTake = dp[i - 1][t];

                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1] [t - nums[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

// class Solution {
// public:
//     bool solve(int i, int target, vector<int>& nums,
//                vector<vector<int>>& dp) {

//         if (target == 0) return true;
//         if (i == 0) return nums[0] == target;

//         if (dp[i][target] != -1)
//             return dp[i][target];

//         bool notTake = solve(i - 1, target, nums, dp);

//         bool take = false;
//         if (nums[i] <= target)
//             take = solve(i - 1, target - nums[i], nums, dp);

//         return dp[i][target] = (take || notTake);
//     }

//     bool canPartition(vector<int>& nums) {
//         int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
//         if (totalSum % 2 != 0) return false;

//         int target = totalSum / 2;
//         int n = nums.size();

//         vector<vector<int>> dp(n, vector<int>(target + 1, -1));

//         return solve(n - 1, target, nums, dp);
//     }
// };
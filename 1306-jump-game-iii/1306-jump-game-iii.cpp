/*

at each index either we go right or left 
but with in safebound 

whenever we enciuter 0 we return true.........

so im thinking we explore both the paths left and right with recursion....

and at the end check 

left || right 

what is the base case

if(nums[idx] == 0) true

if(outofbound) false

*/
class Solution {
public:

    bool dfs(vector<int>& arr,
             int idx,
             vector<int>& vis) {

        // out of bounds
        if(idx < 0 || idx >= arr.size())
            return false;

        // already visited
        if(vis[idx])
            return false;

        // found 0
        if(arr[idx] == 0)
            return true;

        // mark visited
        vis[idx] = 1;

        // explore right and left
        return dfs(arr, idx + arr[idx], vis) ||
               dfs(arr, idx - arr[idx], vis);
    }

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        vector<int> vis(n, 0);

        return dfs(arr, start, vis);
    }
}; 
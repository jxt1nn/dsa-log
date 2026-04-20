/*
    brute force 

    find fathest differnt number from our number 
    O(n^2)

    but wait.......

    we only care about maximum distance
    
    to make it maximum, you want j as far as possible from i
    The farthest positions in an array are:

    index 0
    index n-1

    So instead of checking every pair:
    Compare:

    nums[i] with nums[n-1]
    nums[i] with nums[0]

*/
class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != nums[0])
                maxi = max(maxi, i);

            if(nums[i] != nums[n-1])
                maxi = max(maxi, n - 1 - i);
        }

        return maxi;
    }
};
/*
    order dosent matter :

        sort the array 

    what can be the maximum value for n 
    [1,2,3,4,5,6,..........]

    maximum cannot exceed the n 

    min(curr, prev+1)
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = 1;
        nums[0] = 1;
        for(int i = 1;i < nums.size();i++){
            int curr = nums[i];
            int prev = nums[i-1];

            nums[i] = min(curr, prev + 1);
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
};
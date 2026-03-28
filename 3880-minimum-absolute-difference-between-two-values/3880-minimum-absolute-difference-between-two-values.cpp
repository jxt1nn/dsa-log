/*
    pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2

    Return the minimum absolute difference between i and j 
    among all valid pairs. 
    If no valid pair exists, return -1.

*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int one = -1;
        int two = -1;
        int mini = INT_MAX;
        for(int i =0;i < nums.size();i++){
            if(nums[i] == 1){
                one = i;
            }
            if(nums[i] == 2){
                two = i;
            }

            if(one != -1 && two != -1){
                mini = min(mini,abs(one-two));
            }
        }
        return mini == INT_MAX ? -1 : mini;        
    }
};
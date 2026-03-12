class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int bob = 0;
        int alice = 0;

        int i = 0;
        int j = nums.size() - 1;
        bool f = true;

        while(i < j){
            if(f){
                alice += max(nums[i],nums[j]);
                if(nums[i] > nums[j]){
                    i++;
                }
                else{
                    j--;
                }
            }
            else{
                bob += max(nums[i],nums[j]);
                if(nums[i] > nums[j]){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return alice > bob ? true : false;
    }
};
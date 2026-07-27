class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int f = 0;
       int s = 0;

       for(int i =0; i < nums.size();i++){

            if(nums[i] > f){
                s = f;
                f = nums[i];
            }
            else if(nums[i] > s){
                s = nums[i];
            }
       }
       return (s - 1) * (f - 1);
    }
};
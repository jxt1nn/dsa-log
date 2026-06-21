/*

    no order matters 

    just do soorting and take as much ice cream as can
    
*/
class Solution {
public:
    int maxIceCream(vector<int>& nums, int coins) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int  i =0;i < nums.size();i++){
            if(nums[i] <= coins){
                cnt++;
                coins -= nums[i];
            }
        }
        return cnt;
    }
};
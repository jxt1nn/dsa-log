/*
    brute force 

    find fathest differnt number from our number 
    O(n^2)



*/
class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int maxi = 0;

        for(int i =0;i < nums.size();i++){ 
            for(int j = nums.size()-1;j >= i;j--){
                if(nums[i] != nums[j]){
                    maxi =  max(maxi,abs(i-j));
                    break;
                }
            }
        }
        return maxi;
    }
};
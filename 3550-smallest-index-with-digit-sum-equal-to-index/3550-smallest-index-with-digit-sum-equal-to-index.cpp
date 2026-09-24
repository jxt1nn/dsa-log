class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for(int i =0;i < nums.size();i++){
            int num = nums[i];
            int sum = 0;

            while(num > 0){
                int ld = num % 10;
                num /= 10;
                sum += ld;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;
        int n = nums.size();

        for(int i = n-1;i >= 0;i--) {
            int num = nums[i];

            while(num){
                int last = num % 10;
                result.push_back(last);
                num /= 10;
            }
        } 
        reverse(result.begin(),result.end());
        return result;
    }
};
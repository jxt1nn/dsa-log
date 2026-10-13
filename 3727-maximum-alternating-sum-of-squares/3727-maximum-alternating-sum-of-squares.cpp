class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int MOD = 1e9 + 7;
        for(int i =0;i < nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i = 0,j = nums.size()-1;
        long long sum = 0;
        int n = nums.size() % 2;
        while(i < j){
            long long l = 1LL * nums[i] * nums[i];
            long long r = 1LL * nums[j] * nums[j];

            sum -= l;
            sum += r;

            i++;
            j--;
        }
        if(n){
            sum += nums[i] * nums[i];
        }
        return sum;
    }
};
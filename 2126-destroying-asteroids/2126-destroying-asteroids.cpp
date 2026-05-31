class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());

        long long m = mass;
        for(int i = 0;i < nums.size();i++){
            if( m < nums[i]){
                return false;
            }
            m += nums[i];
        }
        return true;
    }
};
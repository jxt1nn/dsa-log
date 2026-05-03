class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        for(int i =0 ; i < n;i++){
            if(nums[i] <= i){
                v.push_back({i-nums[i],nums[i]});
            }
        }

        sort(v.begin(),v.end());

        vector<int> lis;

        for(auto& [_,val] : v){
            auto it = lower_bound(lis.begin(),lis.end(),val);
            if(it == lis.end()) lis.push_back(val);
            else *it = val;
        }

        return lis.size();
    }
};
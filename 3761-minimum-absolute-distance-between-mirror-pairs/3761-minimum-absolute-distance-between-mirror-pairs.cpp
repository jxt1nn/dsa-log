class Solution {
public:
    /*
    we just store the index of nums[i] in mpp

    and in future we will get rev number that is previously seen we check and 
    find the distance

    one more thing a number can be seen multiple time so need to store the clost value 
    bcoz we need to find MINIMUM distance 
    */
    int revNum(int x){
        int rev = 0;
        while(x > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
     int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                res = min(res, i - mp[nums[i]]);
            }
            mp[revNum(nums[i])] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;
        int mcnt = 1;

        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[i-1]){
                mcnt++;
            }
            else{
                maxi = max(maxi,mcnt);
                mcnt = 1;
            }
        }
        maxi = max(maxi,mcnt);
        int scnt = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < nums[i-1]){
                scnt++;
            }
            else{
                mini = max(mini,scnt);
                scnt = 1;
            }
        }
        mini = max(mini,scnt);
        return max(maxi,mini);
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        vector<int> sortNums = nums;
        sort(sortNums.begin(),sortNums.end());
        unordered_map<int,int> mpp;

        int rank = 1;

        for(int i = 0;i < sortNums.size();i++){

           if (i == 0 || sortNums[i] != sortNums[i - 1]) {
                mpp[sortNums[i]] = rank;
                rank++;
            }

        }

        for(int i = 0; i < nums.size();i++){
            nums[i] = mpp[nums[i]];
        }
        return nums;

    }
};
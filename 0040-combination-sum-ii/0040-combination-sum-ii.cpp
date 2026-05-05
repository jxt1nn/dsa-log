/*

    limited use of number 






*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int index, int target, vector<int>& nums) {

        //base case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        //invalid cases
        if (target < 0 || index == nums.size()) return;

        //TAKE
        temp.push_back(nums[index]);
        backtrack(index + 1, target - nums[index], nums);
        temp.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        //SKIP
        backtrack(index + 1, target, nums);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        backtrack(0, target, nums);
        return ans;
    }
};
/*

    "all unique combinations".............
    BACKTRACKING!!!!!!!!!!!!!!!!!!!!!

    goal : sum == target 
    choice : take an element as much i want
    constraint : dont exceed target
    base case : hit target



    BASE CASE :

    i(target == 0){
        ans.push_back(temp);;
    }

    2 choics

    take / not take 





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
        backtrack(index, target - nums[index], nums);
        temp.pop_back();

        //SKIP
        backtrack(index + 1, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0, target, candidates);
        return ans;
    }
};
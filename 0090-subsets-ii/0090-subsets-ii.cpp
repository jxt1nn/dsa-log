/*
all possible subsets : backtrack 

    subset 
    goal : find all subset 
    choices : pick/skip
    constraints : no duplicate subset  
    base case : reached end

    how to write logic??????????????

    what should we do of dupilcate elements 
    “Avoid picking the same value again at the same level”
    we have to skip them

    how???????????

    this is our if condition 

    pick 
    exlore 
    undo
    check
    explore


*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

     void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, nums);
        temp.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        solve(i + 1, nums);
    }    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return ans;
    }
};
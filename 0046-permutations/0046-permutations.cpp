/*
    permutation
    "all the possible permutations"
    BACKRACKING............

    goal : all permutation 
    choices : take the any unused element 
    constraint : cant use used element 

    base Case : temp size == nums.size();

    loop...........
    how many choics on each step 
    0 to n

    for(all possible choices){
        if(check used) continue ;

        choose 

        explore 

        undo
    }



*/
class Solution {
public:
    vector<vector<int>> result;

    void solve(int index, vector<int>& nums, vector<int>& used, vector<int>& local) {
        
        // base case
        if (index == nums.size()) {
            result.push_back(local);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            // choose
            used[i] = 1;
            local.push_back(nums[i]);

            // recurse
            solve(index + 1, nums, used, local);

            // undo (backtrack)
            local.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> used(n, 0);
        vector<int> local;

        solve(0, nums, used, local);

        return result;
    }
};
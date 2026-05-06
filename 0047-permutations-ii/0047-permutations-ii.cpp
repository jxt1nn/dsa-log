/*
    permutation
    "all the possible permutations"
    BACKRACKING............

    goal : all permutation 
    choices : take the any unused element 
    constraint : cant use used element 

    but we have a condition we have duplicate element also 
    
    allow first occurrence, skip repeated ones at same level
        “Use duplicate only if the previous identical one is already used”

    if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
    continue;

    START: temp = [], used = [0,0,0]

    Level 0:
    ├── i=0 → pick 1 → [1] used=[1,0,0]
    │
    │   Level 1:
    │   ├── i=0 ❌ (already used)
    │   ├── i=1 → pick 1 → [1,1] used=[1,1,0]
    │   │
    │   │   Level 2:
    │   │   ├── i=0 ❌
    │   │   ├── i=1 ❌
    │   │   ├── i=2 → pick 2 → [1,1,2] ✅ (store)
    │   │
    │   │   🔙 undo → [1,1]
    │
    │   ├── 🔙 undo → [1]
    │
    │   ├── i=2 → pick 2 → [1,2] used=[1,0,1]
    │       │
    │       Level 2:
    │       ├── i=0 ❌
    │       ├── i=1 → pick 1 → [1,2,1] ✅ (store)
    │       │
    │       🔙 undo → [1,2]
    │
    │   🔙 undo → [1]
    │
    ├── 🔙 undo → []
    │
    ├── i=1 ❌ SKIP (duplicate)
    │     because nums[1]==nums[0] AND used[0]==0
    │
    ├── i=2 → pick 2 → [2] used=[0,0,1]
        │
        Level 1:
        ├── i=0 → pick 1 → [2,1] used=[1,0,1]
        │   │
        │   Level 2:
        │   ├── i=1 → pick 1 → [2,1,1] ✅ (store)
        │   │
        │   🔙 undo → [2,1]
        │
        ├── 🔙 undo → [2]
        │
        ├── i=1 ❌ SKIP (duplicate)
        │
        🔙 undo → []



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

            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> used(n, 0);
        vector<int> local;
        sort(nums.begin(),nums.end());

        solve(0, nums, used, local);

        return result;
    }
};
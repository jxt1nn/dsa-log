/*
all possible subsets : backtrack 

    subset 
    goal : find all subset 
    choices : pick/skip
    constraints : none 
    base case : reached end

    how to write logic??????????????

    base case :
    if(i == size()){
        ans.push_back(temp)
    }

    loop?????????

    should we need loop???????????

    1.make choice 

    pick : temp.push_back(nums[i])
    explore : (i+1)

    undo : pop_back
    explore........
    

    no we doesnt use loop bcoz of only 2 choices present




*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(int index,vector<int>& nums){
    
        ans.push_back(temp);

        for(int i = index;i < nums.size();i++){
             //make choice 
            temp.push_back(nums[i]);

            //explore
            solve(i+1,nums);

            //undo 
            temp.pop_back();

        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;        
    }
};
/*  

    return first stable index

    what is stable index??????????
    max(nums[0..i]) - min(nums[i..n - 1]).

-> max(nums[0..i]) is the largest value
    among the elements from index 0 to index i.

-> min(nums[i..n - 1]) is the smallest value
    among the elements from index i to index n - 1.

we can compute min element gradualy.....

as increase i compute min element also....

and compute max at the moment 

for now then i will think more....






*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size();i++){
            maxi = max(maxi,nums[i]);
            int mini = INT_MAX;
            for(int j = i; j < nums.size();j++){
                mini = min(mini,nums[j]);
            }
            if(( maxi - mini ) <= k){
                return i;
            }
        }
        return -1;


    }
};
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


this is O(n^2)

so what we need ??????????

max from left at each index 
    and min from right at each index 

we can crete suffix and prefx 

what prefix do store the max till ith index from left 

    suffix store min till i from right

but we got problem only in suffix
prefix we can calcuate at the moment


*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n);
        mini[n-1] = nums[n-1];
        
        //suffix
        for(int i = n-2; i >= 0; i--){
            mini[i] = min(nums[i], mini[i+1]);
        }

        int maxi =  INT_MIN;

        for(int i =0; i < n;i++){
            maxi = max(maxi,nums[i]);

            if((maxi - mini[i]) <= k){
                return i;
            }
        }        

        return -1;

        //     maxi = max(maxi,nums[i]);
        //     int mini = INT_MAX;
        //     for(int j = i; j < nums.size();j++){
        //         mini = min(mini,nums[j]);
        //     }
        //     if(( maxi - mini ) <= k){
        //         return i;
        //     }
        // }
        // return -1;
    }
};
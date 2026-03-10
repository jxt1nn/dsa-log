/*
    we have to find next permutation...........

    Find the next greater arrangement of the same numbers
        [1,2,3] → next → [1,3,2]

    [2,1,3]
    [2,3,1]   ← current
    [3,1,2]   ← next
    [3,2,1]

    (Important Case)
    
    [3,2,1]

    This is the largest permutation already.

    There is no next permutation.
    So we return the smallest permutation:

    [1,2,3]

    Move from right → left and find the first place where:

    nums[i] < nums[i+1]

    [1,2,3,6,5,4]
             ↑

    5 > 4  ❌
    6 > 5  ❌
    3 < 6  ✅
    
    So the pivot index = 2

    [1,2,3 | 6,5,4]
         ↑

    Now again move from the right side and find the smallest number greater than pivot.

    6,5,4
        The next greater number from the right is: 4

    swap them : [1,2,4,6,5,3]

    right part : 6,5,3

    cureently in decreasing order 

    we have to make it as small as possible 

    so we just sort it or reverse it.....

        Edge Case

        If the array is completely decreasing: [5,4,3,2,1]
    
    no pivot found 
    reverse entire array

    steps : 

    1. Find first decreasing point from right
    2. Swap with just greater element
    3. Reverse the right part
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the first decreasing element from right
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If pivot found, swap with next greater element
        if(pivot != -1) {
            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
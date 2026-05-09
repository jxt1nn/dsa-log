/*

    pattern does NOT store actual values............

    it stores RELATIONSHIP
    between adjacent elements

---------------------------------------------------------

    pattern values meaning:

        1  -> increasing
        0  -> equal
       -1  -> decreasing

---------------------------------------------------------

    Example:

    nums = [3,5,5,2]

---------------------------------------------------------

    comparisons:

    3 -> 5   increasing  -> 1
    5 -> 5   equal       -> 0
    5 -> 2   decreasing  -> -1

---------------------------------------------------------

    transformed array becomes:

    [1,0,-1]

---------------------------------------------------------

    IMPORTANT OBSERVATION................

    pattern size = m

    but required subarray size = m+1

---------------------------------------------------------

    WHY?????????

    because:

        m comparisons

    need:

        m+1 numbers

---------------------------------------------------------

    Example:

    [3,5,5,2]

    comparisons are:

        3 -> 5
        5 -> 5
        5 -> 2

    total comparisons = 3

    total numbers = 4

---------------------------------------------------------

    MAIN INTUITION................

    instead of checking:

        nums[i+1] > nums[i]
        nums[i+2] == nums[i+1]
        nums[i+3] < nums[i+2]

    again and again for every subarray,

---------------------------------------------------------

    transform nums into
    comparison/sign array

---------------------------------------------------------

    Example:

    nums = [1,4,4,2,5]

---------------------------------------------------------

    build compare array:

    1 -> 4 = 1
    4 -> 4 = 0
    4 -> 2 = -1
    2 -> 5 = 1

    nums[i] > nums[i-1]
    nums[i] == nums[i-1]
    nums[i] < nums[i-1]
---------------------------------------------------------

    compare = [1,0,-1,1]

---------------------------------------------------------

    now problem becomes:

        find pattern inside compare array

---------------------------------------------------------

    Example:

    pattern = [0,-1]

---------------------------------------------------------

    compare array:

    [1,0,-1,1]

---------------------------------------------------------

    subarray:

    [0,-1]

    matches pattern

---------------------------------------------------------

    so actual problem is NOT
    about numbers anymore

---------------------------------------------------------

    it becomes:

        pattern matching problem

---------------------------------------------------------

    FINAL MENTAL MODEL................

    nums
        ->
    comparison/sign array
        ->
    find pattern occurrences

---------------------------------------------------------

    COMMON TRICK:

    whenever you see:

        greater than
        smaller than
        equal

    between neighboring elements,

    think:

        convert into movement array

*/
class Solution {
public:

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {

        int n = nums.size();
        int m = pattern.size();

        /*

            STEP 1 :
            build comparison array

            1  -> increasing
            0  -> equal
           -1  -> decreasing

        */

        vector<int> compare;

        for(int i = 0; i < n - 1; i++) {

            if(nums[i + 1] > nums[i]) {
                compare.push_back(1);
            }
            else if(nums[i + 1] == nums[i]) {
                compare.push_back(0);
            }
            else {
                compare.push_back(-1);
            }
        }

        /*

            STEP 2 :
            find pattern occurrences

        */

        int count = 0;

        for(int i = 0; i <= compare.size() - m; i++) {

            bool match = true;

            for(int j = 0; j < m; j++) {

                if(compare[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if(match) {
                count++;
            }
        }

        return count;
    }
};
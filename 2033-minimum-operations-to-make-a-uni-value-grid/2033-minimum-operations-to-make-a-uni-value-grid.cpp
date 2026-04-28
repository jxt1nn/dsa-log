/*

As we are asked in the question to find the minimum numbers of moves 
to make all the elements in the grid equal........
our first intuition should be finding what that number is????????


That number should be the median of the elements as the median is the optimal element
to minimise the increments/decrements of other elements in the grid.


Convert the 2D vector into a 1D linear vector......

Find the median of this vector by directly accessing the middle element.

Find the difference of all the elements 
    from the median and calculate the number of operations required to convert all the numbers to the median by using abs(number - median) / x.

If we reach a number such that abs(number - median) % x != 0 
then we return false as that number can not be converted 
into the median by any number of operations.

*/
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for (auto &row : grid) {
                for (int k : row) {
                    nums.push_back(k);
                }
            }
            sort(nums.begin(), nums.end()); 
            int target = nums[nums.size() / 2];
            long long totalOperations = 0;
            for (int k : nums) {
                int temp = abs(k - target);
                if (temp % x != 0) return -1;
                totalOperations += temp / x; 
            }
            return totalOperations;
        }
    };
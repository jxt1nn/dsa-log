/*  
    The string is called alternating if two adjacent characters are not equal

    their can be 2 pattern 
        start with 0 -> 0101010
        start with 1 -> 1010101
     
    So the minimum number of operations required will be the minimum between these two counts

    how to count for 1 pattern
        for 01010101

    even index should be 0
    and 
    odd index should be 1.........

    so for every index check

    int expected = (i % 2 == 0) ? '0' : '1';

    if(nums[i] != expected) count++;

    this code give us mistamtch for 01010101 pattern

    for 10101010 pattern 
        we dont need to recalculate just do...

    mis1 = n - mis0

*/
class Solution {
public:
    int minOperations(string s) {
        int mis0 = 0,mis1 = 0;

        for(int i =0;i < s.size();i++){
            int expected = (i % 2 == 0) ? '0' : '1';

            if(s[i] != expected) mis0++;
        }
        mis1 = s.size() - mis0;
        return min(mis1,mis0);
    }
};
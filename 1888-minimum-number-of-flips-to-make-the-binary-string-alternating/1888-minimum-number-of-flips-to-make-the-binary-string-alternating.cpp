/*
    string is called alternating if no two adjacent characters are equal


    we can perform 2 types of opeartion on string to make it alternative 

    Type-1:
    Remove the character at the start of the string s and append it to the end of the string.

    Type-2:
    Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1'and
    vice-versa

    Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

    we know type 1 operation desnt cost anything us 

    for exmample we have string 

        10100
    
    do type 1 opration on this 
    possible strings 
        01001
        10010
        00101
        01010
        10100

    we have to check all this string....

    ehat we gonna check ???
        minimum opeartion to make string alternating (1758 leetcode)

    their will be 2 patterns :
        start with 0 -> 0101010
        start with 1 -> 1010101

    how to count for 1 pattern :
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

    so their will be a afunction called rotate 
        rotate(s.begin(), s.begin() + 1, s.end());

    we can get rotated string by 1 place 
        then perform match function on this

    this roatate function cost us O(n) everytime

    this method is completly brute FORCE........
    O(n rotations × n check) = O(n²)

    Rotating string again and again is expensive

    💡 Key observation
    All rotations of s exist inside:
    t = s + s

    s = "1100"
    t = "11001100"

    All rotations:
        1100
        1001
        0011
        0110

    Instead of rotating:
    Use sliding window of size n on t
    
    still :
    O(n windows × n check) = O(n²)

    Use sliding window + incremental update
        mis0 = mismatches with "010101..."

    When adding new character:
        if(t[i] != expected) mis0++

    When removing old character:
        if(t[left] != expected_left) mis0--

    Optimize pattern checking
        instead of check both patterns 

    mis0 = mismatches with "0101..."
        mis1 = n - mis0
        
*/
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string t = s + s;
        int ans = n;
        int mis0 = 0;

        for(int i = 0 ; i < 2*n;i++){
            // for 0101010

            char expected = (i % 2 == 0) ? '0' : '1';
            if(t[i] != expected) mis0++;    

            if(i >= n){ // window gets bigger than n-1
                // need to shrink
                int left = i - n;
                char left_expected = (left % 2 == 0) ? '0' : '1';
                if(t[left] != left_expected) mis0--;
            }

            if(i >= n-1){  // window size is n now 
                int mis1 = n - mis0;
                ans = min(ans,min(mis1,mis0));
            }
        }
        return ans;
    }
};
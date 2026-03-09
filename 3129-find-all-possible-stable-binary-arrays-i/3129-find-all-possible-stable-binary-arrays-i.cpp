/*
    the size of stable binary array  is alwaays.......

    SizeOfArr = zero + one

    we have to make multiple stable arrays
    that follow some constraints.........

    The number of occurrences of 0 in arr is exactly zero.

    The number of occurrences of 1 in arr is exactly one.

    Each subarray of arr with a size greater than limit must contain both 0 and 1.

    we can make total number of arrays from 
        zero AND one

    size = 1 + 1
    number of array = n! 

    from this n! arrays we have to to filter it out 
    those array whose

    Each subarray of arr with a size greater than limit must contain both 0 and 1

    means if limit is 2 

        we cannott take more than limit consecutive 1s or 0s

    we should change it before it exceeed the limit...........

    bcoz if take more than limit 
    it will became 000

    and this is a subarray of size > limit and its doesnt contain both 1s and 0s

    so for  every time we have 2 choices 

    if last element is 0 
        we have to take 1 

    if last element is 1 
        we have to take 0
    
    how many consecutive 1s or 0s we can take 

    min(limit,zero)
    min(limit,one)

    
    we can start from taking 0 OR 1 
    

*/
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if(onesLeft == 0 && zerosLeft == 0) {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
            return t[onesLeft][zerosLeft][lastWasOne];
        }


        int result = 0;

        if(lastWasOne == true) { //explore 0s
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { //explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;

    }
};
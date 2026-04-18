/*

    reverse the n :

    Extract digits from n using n % 10
    
    Build the reversed number by appending digits:
        a = a * 10 + (n % 10);
    
    Remove the last digit from n using n /= 10.
        n /= 10;
    
    Repeat until n becomes 0
     
    then :
    calculate 
        abs(n - reverse(n))


*/
class Solution {
private:
    int rev(int n) {
        int a = 0;
        while(n > 0) {
            a = a * 10 + (n % 10);
            n /= 10;
        }
        return a;
    }
public:
    int mirrorDistance(int n) {
        int m = rev(n);
        return abs(m - n);
    }
};
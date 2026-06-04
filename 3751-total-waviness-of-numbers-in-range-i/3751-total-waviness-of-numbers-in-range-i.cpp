class Solution {
public:
    /*
    by third example we can see that a single number acn have more than 
    one valley or peak 

    for checking velly and peak we can select 3 digit of a number and check it
    for now idk why i am thinking of checking all the numbers 
    */
    int wave(int n){
        if(n < 100) return 0;

        string s = to_string(n);
        int count = 0;
        for(int i = 1; i + 1 < s.size();i++){  
            int a = s[i -1] -'0';
            int b = s[i] - '0';
            int c = s[i + 1] -'0';

            if((b > a && b > c) || (b < a && b < c)){
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        long long ans = 0;

        for(int i = num1;i <= num2 ;i++){
            ans += wave(i);
        }
        return ans;
    }
};
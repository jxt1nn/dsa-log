/*  

    we can only take square of single digit 

    maximum : 9
    minmum : 0

    we have sum variable we try to make number from4as maximum digit possible 

        sum % 9 = additional number other than 9 
        sum / 9 = how many 9

    if(count > num) return EMPTY 

    count:

        (9*10)+9

    number 
        number*10+ additional 

    rem =  numSize - numbeSize 
        rem--
        string.push("0");

    return str 







*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int additional = sum % 9; 
        int N = sum / 9;  // number of 9

        if(N > num) return "";
        string str = "";
        
        while(N > 0){
            str.push_back('9');
            N--;
        }

        if (additional != 0) {
            str.push_back(additional + '0');
        }


        if(str.size() > num) return "";
        int rem = num - str.size();

        while(rem > 0){
            str.push_back('0');
            rem--;
        }
        return str;

    }
};
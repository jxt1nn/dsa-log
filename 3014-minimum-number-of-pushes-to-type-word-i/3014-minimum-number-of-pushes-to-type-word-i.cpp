/*



    count disntict char

    first 8 : one tap 
    second 8 : two tap
    third 8 : three tap
    last 2 : four tap

    24/8 = 3







*/
class Solution {
public:
    int minimumPushes(string word) {

        int len = word.size();

        if(len <= 8) return len;
        int sum  = 0;

        int i = 1;
        while(i <= len){
            if(i <= 8){
                sum += 1;
            }
            else if(i > 8 && i <= 16){
                sum += 2;
            }
            else if(i > 16 && i <= 24){
                sum += 3;
            }
            else{
                sum += 4;
            }
            i++;
        }
        return sum;
    }
};
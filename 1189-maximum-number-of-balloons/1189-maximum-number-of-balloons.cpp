/*

    count the charcters comes in ballon 

    take the minimum frequeecy from all

    if all have frequenecy  
        possible 
    otherwise not 


*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
            vector<int> freq(26,0);

            for(char ch : text){
                freq[ch - 'a']++;
            }
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
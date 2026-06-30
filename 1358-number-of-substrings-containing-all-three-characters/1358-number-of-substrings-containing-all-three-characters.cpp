/*

    string + substring + number of substrings 
    SCREAMS sliding window
    
    number of substring????????????
        TYPE 3 

    calcuate substring have <= 3 character 
    and < 3 character

    and subtract <= (-) < 

    how to calculate it 
    
    for k-1 :
    expand :  maitain freq 
    shrink : when ever freq of a && b && c 



*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
       long long LessThanEqualto = 1LL * n * (n + 1) / 2;

        int l = 0;
        int r = 0;
        int subCount = 0;
        vector<int> freq(3, 0);

        while (r < n) { // substrings here only 2 or > charcters present
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) { // means the addition of this three is can be == 3
                freq[s[l] - 'a']--;
                l++;
            }

            subCount += (r - l + 1);
            r++;
        }

        return LessThanEqualto - subCount;
    }
};
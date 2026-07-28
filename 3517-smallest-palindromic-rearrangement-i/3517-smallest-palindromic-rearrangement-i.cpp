/*

    we have to make  lexicographically smallest palindromic

    with character present in string s

    how to make palindrome which is lexico. smallest???????????

    try make a string which is lexigro. smallest 

    Count frequency

    left = ""
    middle = ""

    for every character from a to z

        add freq[i]/2 copies to left

        if(freq[i] is odd)
            middle = character

    right = reverse(left)

    return left + middle + right


*/
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);

        for(int i = 0; i < s.size();i++){
            freq[s[i] - 'a']++;
        }        
        string left = "";
        string middle = "";
        
        for(int i =0; i < freq.size();i++){
            int num = freq[i];
            num = num / 2;
            while(num > 0){
                left.push_back('a' + i);
                num--;
            }

            if(freq[i] % 2 == 1){
                middle.push_back('a' + i);
            }
        }
        string right = left;
        reverse(right.begin(),right.end());

        return left + middle + right;
    }
};
/*

    each number map with some char 
    and we can use any char 

    and move to next index number 

    return all possible letter combinations that the number could represent
    
    screams BACKTRACKINGGGGGGGGGGGG............

    
    2-9 digit map with char 
    like:
    2 : a b c 
    3 : d e f
    4 : g h i

    what we do????

    take a digit 

    choose a char
    go deeper
    undo the choose

    what is the base case????????
    
    if(str.size() == digits.size()){
        ans.push_back(str);
        return;
    }

    for(all choics){

        choose 

        explore

        backtrack(undo)

    }

    how we loop on a practicular digit map charcters????

    vector<vector<string>> 
    then start mapping 








*/
class Solution {
public:

    vector<string> ans;

    string mapping[10] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string& digits,
               int index,
               string& path) {

        // base case
        if(index == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for(char ch : letters) {

            // choose
            path.push_back(ch);

            // explore
            solve(digits, index + 1, path);

            // backtrack
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0)
            return {};

        string path = "";

        solve(digits, 0, path);

        return ans;
    }
};
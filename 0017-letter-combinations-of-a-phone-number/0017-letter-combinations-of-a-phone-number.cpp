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

    how we loop on a particular digit map characters???

    example:
        digits = "23"

        digit '2' -> "abc"
        digit '3' -> "def"

    so for each digit:
        we need all characters mapped to it


    WRONG IDEA:
        vector<vector<string>>
        (NOT needed, overkill ❌)


    CORRECT IDEA:

        use direct mapping array:

        string mapping[10] = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };


    WHY THIS WORKS???

        digit is a character:
            '2', '3', etc.

        convert it to index:
            digits[index] - '0'


        example:
            '2' - '0' = 2
            so mapping[2] = "abc"


    SO LOOP BECOMES:

        string letters = mapping[digits[index] - '0'];

        for(each char in letters){

            choose character
            go deeper
            undo (pop)
        }


    FINAL FLOW:

        for each digit:
            get its string of letters
            try every letter
            backtrack



*/
class Solution {
public:

    vector<string> ans;

    vector<string> mapping = {
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
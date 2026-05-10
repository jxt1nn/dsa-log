/*

    all possible palindrome partitioning of s

    BACKTRACKING............

    we have  to try all possible string

    how???

    gradualy make string and each step check if its valid
    if yes store the answer 

    if not  add anotrher charchter...........

    like
    void solve(state) {

    if(base_case) {
        store answer;
        return;
    }

    for(all choices) {

        if(valid choice) {

            choose

            solve(next state)

            undo choice
        }
    }
}

string = abcaa

From index 0:

"a"   ✅
"ab"  ❌
"abc" ❌
"abca" ❌
"abcaa" ❌
    

From index 1:

"b" ✅
"bc" ❌
"bca" ❌
...

do same for every index........

level by level.........


*/
class Solution {
public:

    vector<vector<string>> ans;

    // check palindrome
    bool isPalindrome(string &s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void solve(int index, string &s, vector<string> &path) {

        // complete partition
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        // try every substring starting from index
        for (int end = index; end < s.size(); end++) {

            // choose only palindrome substring
            if (isPalindrome(s, index, end)) {

                path.push_back(s.substr(index, end - index + 1));

                solve(end + 1, s, path);

                // backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> path;

        solve(0, s, path);

        return ans;
    }
};
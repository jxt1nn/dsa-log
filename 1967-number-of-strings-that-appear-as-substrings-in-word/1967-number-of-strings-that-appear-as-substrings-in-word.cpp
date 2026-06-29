class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;

        for (string str : patterns) {
            if (word.find(str) != string::npos) {
                count++;
            }
        }

        return count;
    }
};
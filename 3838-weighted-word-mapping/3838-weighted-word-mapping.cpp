class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (string &word : words) {
            int current_weight = 0;

            for (char ch : word) {
                current_weight += weights[ch - 'a'];
            }

            int mod_val = current_weight % 26;

            // reverse alphabet mapping
            result += char('z' - mod_val);
        }

        return result;
    }
};
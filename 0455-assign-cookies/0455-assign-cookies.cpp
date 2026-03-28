/*
    Each child i has a greed factor g[i]

    each cookie j has a size s[j]

    If s[j] >= g[i], we can assign the cookie j to the child i

    Can I make a local best choice?
    YES

    sort both the arrays

    travers in both 

    if(s[j] >= g[i]){
        ans 
    }
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]) {
                i++;  // child satisfied
                j++;  // cookie used
            } else {
                j++;  // try bigger cookie
            }
        }

        return i;
    }
};
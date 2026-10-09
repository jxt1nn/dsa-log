class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int ans = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                count++;
                i++;
            }
            else{   
                if(count > 0){
                    count--;
                }
                else{
                    ans++;
                }

                if(i + 1 < s.size() && s[i+1] == ')'){
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
            }
        }
        ans = ans + (count * 2);
        return ans;
    }
};
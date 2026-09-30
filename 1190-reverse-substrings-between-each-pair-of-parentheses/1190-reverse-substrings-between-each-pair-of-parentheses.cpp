class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i =0; i < s.size();i++){
            if(s[i] == ')'){
                string str = "";
                while(st.top() != '('){
                    char t =  st.top();
                    st.pop();
                    str += t;
                }
                st.pop();
                for(int j =0; j <  str.size();j++){
                    st.push(str[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            char f = st.top();
            st.pop();
            if(f != '(') ans += f;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
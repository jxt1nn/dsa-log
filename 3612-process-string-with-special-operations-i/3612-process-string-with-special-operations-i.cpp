/*


    just use one loop and do whatever question says 



*/
class Solution {
public:
    string processStr(string s) {

        string res = "";

        for(int i = 0;i < s.size();i++){

            if(s[i] == '*'){
                int resSize = res.size();
                
                if(resSize > 0){
                    res.pop_back();
                }

            }
            else if(s[i] == '#'){

                if(res != ""){

                    string temp = res;
                    res += temp;

                }

            }
            else if(s[i] == '%'){

                reverse(res.begin(),res.end());

            }
            else{
                res += s[i];
            }          
        }
        return res;
    }
};
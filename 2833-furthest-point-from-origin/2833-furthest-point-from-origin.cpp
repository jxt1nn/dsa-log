/*

    just count the L R _

    and which ever grester in between L R 

    add count of _ in that and return ans 

*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int p = 0,d = 0;

        for(auto it : moves){
            if(it == 'L'){
                p--;
            }else if(it == 'R'){
                p++;
            }
            else{
                d++;
            }
        }

        return abs(p) + d;
    }
};
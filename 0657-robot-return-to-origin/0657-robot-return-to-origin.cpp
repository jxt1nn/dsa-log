/*

    origin is (0,0)

    we can move 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

    Return true if the robot returns to the origin after it finishes all of its moves,
    false otherwise.

    take 2 variables 
        1. for vertical movements (v) 
        2. for horizontal movements (h)

    when we move L : h - 1
                 R : h + 1

                 U : v - 1
                 D : v + 1

    when we finish all moves check 
    if v and h is still 0 or not
                   
     
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0,h = 0;

        for(char c : moves){
            if(c == 'L'){
                h -= 1;
            }else if(c == 'R'){
                h += 1;
            }else if(c == 'U'){
                v -= 1;
            }else{
                v += 1;
            }
        }

        return (v == 0 && h == 0);
    }
};
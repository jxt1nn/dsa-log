/**
    we are intially on index 0

    each element in the array represents your maximum jump length at that position
    return the minimum number of jumps to reach index n - 1.

    test cases are generated such that you can reach index n - 1

    nums = [2,3,1,1,4]
    from index 0, you can go to:
    [1, 2]

    in 1 jump, I can reach indices [1...2]

    From that range, where can you go next?
        From indices [1...2]:
            From 1 → reach 4
            From 2 → reach 3

    So in 2 jumps, you can reach:
    [3...4]

    so this will became a layer system......

    we are moving in layers (ranges):

    Jumps	Reachable Range
        0       [0]
        1	    [1...2]
        2	    [3...4]
  
    Convert this idea into variables
    

    Current layer boundary :
        currentEnd

    Next layer boundary:
        maxReach

    When do you take a jump?
        if(i == currentEnd)
    
    “I have used all options in current jump → now I must jump”

    What happens after jump?
        jumps++;
        currentEnd = maxReach;

                🧠 One-line intuition (remember this)
“Process the array in ranges, and increase jumps when the current range ends


*/
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int currentEnd = 0;
        int maxReach = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            
            maxReach = max(maxReach, i + nums[i]);
            
            if(i == currentEnd){
                jumps++;
                currentEnd = maxReach;
            }
        }
        
        return jumps;
    }
};
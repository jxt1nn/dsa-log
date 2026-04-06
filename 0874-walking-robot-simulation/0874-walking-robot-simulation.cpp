/*
    we currently at (0,0) facing north 
    
    three possible types of instructions the robot can receive:
        -2: Turn left 90 degrees.
        -1: Turn right 90 degrees.
         1 <= k <= 9: Move forward k units, one unit at a time


    North means +Y direction.
    East means +X direction.
    South means -Y direction.
    West means -X direction.

    if we are facing some a direction and -1 command recive what will we do????

    N -> E
    S -> W
    E -> S
    W -> N

    -2 command recive what will we do????

    N -> W
    S -> E
    E -> N
    W -> S

    but how to think this thing in code 
    mapping became very messy 

           North (0)
                ↑
     West (3)       East (1)
                ↓
            South (2)

    clockwise order:

        0 → North
        1 → East
        2 → South
        3 → West

    Think of it like a cycle:
        0 (N) → 1 (E) → 2 (S) → 3 (W) → back to 0

    Right Turn (-1) :
    North → East → South → West → North
    0       1       2       3      0

    SO, dir = dir + 1;
    But wait…
    If dir = 3 (West) and you do:

    dir = 3 + 1 = 4 ❌ (invalid)
        We only have 0–3 so we use :
    dir = (dir + 1) % 4;
    bcoz (4 % 4 = 0)  3 → (3+1)%4 = 0 (West → North ✅)


    Left Turn (-2):
    North → West → South → East → North
    0       3       2       1      0
    moving one step backward
    So logically:
        dir = dir - 1;

    But problem:
    dir = 0 - 1 = -1 ❌ (invalid)

    Avoid negative using +3
        Instead of -1, we add +3:
    dir = (dir + 3) % 4;
    bocz -1 ≡ +3 (mod 4)
    
    example : (0 + 3) %  4 = 3

    Movement (MOST IMPORTANT PART) :

    👉 How do we move in each direction?
    
    dx = {0, 1, 0, -1}
    dy = {1, 0, -1, 0}

    How did we get this?

    Direction = 0 (North)
        Move UP → y increases
        x stays same
    dx[0] = 0
    dy[0] = +1

    Direction = 1 (East)
        Move RIGHT → x increases
        y stays same
    dx[1] = +1
    dy[1] = 0

    Direction = 2 (South)
        Move DOWN → y decreases
    dx[2] = 0
    dy[2] = -1

    Direction = 3 (West)
        Move LEFT → x decreases
    dx[3] = -1
    dy[3] = 0

    example :
        x = 0, y = 0
        dir = 0 (North)

    move 1 step :

    x += dx[0] → 0
    y += dy[0] → 1

    Turn right:
        dir = (0 + 1) % 4 = 1 (East)
    Move 1 step:
    
    x += dx[1] → 1
    y += dy[1] → 0
    
    DONE for without obstacles

    -> NOW COMES TO OBSTACLES PART

    If command = k
    Instead of:
        x += k * dx[dir];
        y += k * dy[dir];

    Why is this WRONG when obstacles exist?????????

        What if obstacle is at step 2 but k = 5?

    Obstacle Thinking:
        "I will try to move 1 step… check… then next step… check…"

    
    What is the next cell?

        nx = x + dx[dir]
        ny = y + dy[dir]

    then check if (nx,ny) is obstacle or not?????????

    but itrating everu=y time in obstacle array is very costly 

    we can use SET for fast lookups 

    how to code this up????????
    
    *put obstacles in set 
    *dir value curr =  = 0(north)
    *define directions :
        int dx = {0, 1, 0, -1};
        int dy = {1, 0, -1, 0};

    *itrate in commands 
    *make 3 cases :

        -1 : dir = (dir + 1) % 4;
        -2 : dir = (dir + 3) % 4;
        k : (IMPORTANT)

    *for K : Don’t jump directly Use a loop:

    for (int i = 0; i < k; i++) {
        // find next position
        // check obstacle
        // move or break
    } 

    find next position ????
    
    nx = x + dx[dir]
    ny = y + dy[dir]

    check obstacle ??????

    if(st.count({nx,ny})){
        break
    }
    else{
        x = nx;
        y = ny;
        ans = max(ans, x*x + y*y);
    }

    Return the maximum squared Euclidean distance 
    that the robot reaches at any point in its path 

    "AT ANY POINT"

    keep checking it

*/  
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;

        // *put obstacles in set 
        for(auto &it : obstacles) {
            st.insert({it[0], it[1]});
        }

        int dir = 0; //north
        int x = 0,y = 0;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int ans = 0;

        for(int i =0;i< commands.size();i++){
            if(commands[i] == -1){
                // 0 (N) → 1 (E) → 2 (S) → 3 (W) → back to 0
                dir = (dir + 1) % 4;
            }
            else if(commands[i] == -2){
                dir = (dir + 3) % 4;
            }
            else{
                int k  = commands[i];
                for(int j =0;j < k;j++){

                    int nx =  x + dx[dir];
                    int ny =  y + dy[dir];

                    if(st.count({nx,ny})){
                        // OBSTACLE
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};
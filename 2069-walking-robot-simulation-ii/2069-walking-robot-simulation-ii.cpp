/*

bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). 

this means we cannot go out of bound 

for 'X' :
min value of x is 0
max value of x is width - 1

for 'Y' :
min value of y is 0
max value of y is height - 1

grid is aligned with the four cardinal directions ("North", "East", "South", and "West")

robot is initially at cell (0, 0) facing direction "East".
 
effect of direction on {x,y};

    east : +X
    west : -X
    north : +Y
    south : -Y

robot is moving to is out of bounds, the robot instead
turns 90 degrees counterclockwise :

counterClockWise?????????

        0 → East
        1 → South 
        2 → West
        3 → North

turn left 90 degree........
east -> north -> west -> south -> east
0      1       2        3        0
     moving one step backward
 So logically:
        dir = dir + 1;

But wait…
    If dir = 3 (South) and you do:

    dir = 3 + 1 = 4 ❌ (invalid)
        We only have 0–3 so we use :
    dir = (dir + 1) % 4;
    bcoz (4 % 4 = 0)  3 → (3+1)%4 = 0 (South → East ✅)  

Movement (MOST IMPORTANT PART) :

    👉 How do we move in each direction?

        {1, 0},   // East
        {0, 1},   // North
        {-1, 0},  // West
        {0, -1}   // South
    
    example :
        x = 0, y = 0
        dir = 0 (East)

    move 1 step :

    x += dx[0] → 1
    y += dy[0] → 0

-> NOW COMES BOUNDARY CHECK PART.......

dont directly increment {x,y}

Boundary Thinking:
        "I will try to move 1 step… check… then next step… check…"

What is the next cell?

        nx = x + dx[dir]
        ny = y + dy[dir]

then check if (nx,ny) is inBoundary or not?????????

if (nx < 0 || nx >= width || ny < 0 || ny >= height)

👉 If OUT of boundary:
Rotate 90° counterclockwise
    dir = (dir + 1) % 4;
DO NOT move yet → try again with new direction


The robot moves only on the boundary in a cycle 🔥

👉 It never goes inside the grid randomly
👉 It follows a rectangular perimeter path
So total cycle length:

perimeter = 2 * (width + height - 2)

Instead of doing num steps:

    num = num % perimeter;
👉 Because after one full cycle, robot repeats position + direction

Problem:
When:
    num % perimeter == 0

👉 You skip movement completely

BUT according to problem:
If robot completes a full cycle, direction must be updated

Example:
Suppose robot is at (0,0) facing East
You call step(perimeter)

👉 Robot comes back to (0,0)
BUT direction should become South, not East


fix : 
    if(num == 0) num = perimeter;

how to code this up??????????

*inzailize x, y , perimeter, width, heiight, 
dx array, dy array 

*important for step():

    while(num--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(NOT inBOUNDARY) {
                dir = (dir + 1) % 4; // turn left
                recalculate nx and ny
            }
                x = nx;
                y = ny;
            }
        }

*/
class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0 = East, 1 = North, 2 = West, 3 = South
    int perimeter;
    
    vector<pair<int,int>> directions = {
        {1, 0},   // East
        {0, 1},   // North
        {-1, 0},  // West
        {0, -1}   // South
    };
    
    vector<string> dirNames = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        perimeter = 2 * (w + h - 2);
    }
    
    void step(int num) {
        if (perimeter == 0) return;

        num %= perimeter;
        if (num == 0) num = perimeter;

        while (num--) {
            int nx = x + directions[dir].first;
            int ny = y + directions[dir].second;
            // check boundary
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn CCW
                nx = x + directions[dir].first;
                ny = y + directions[dir].second;
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirNames[dir];
    }
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
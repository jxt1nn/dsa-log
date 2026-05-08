/*
    four integers sx, sy, fx, fy, and a non-negative integer t

    In an infinite 2D grid,
    you start at the cell (sx, sy). 
    Each second, you must move to any of its adjacent cells.

    adjcant cells are the 8 cells around it that share at
    least one corner with it.

    means left right up down all four digonals

    Return true if you can reach cell (fx, fy) after exactly t seconds,
    or false otherwise.


    we need to return only true or false.................

    in one second what can we do???????????

    increase or decrease the row and column 
    or wait.......

    we can do both in 1 second by digonal movemnet 

    Because diagonal movement is allowed:

    In one move you can reduce:

    x difference by 1
    AND y difference by 1 simultaneously

    So minimum time is NOT:

    dx + dy

    Instead it is:
    max(dx, dy)

    dx = abs(fx - sx)
    dy = abs(fy - sy)

    Why max(dx, dy)?

    Start:

    (1,1)

    Finish:

    (4,5)

    Differences:

    dx = 3
    dy = 4

    You can move diagonally 3 times:

    (1,1) -> (2,2)
    (2,2) -> (3,3)
    (3,3) -> (4,4)

    Now only y remains.

    One more move:

    (4,5)

    Total:

    4 moves

    which equals:

    max(3,4)


    Now think about EXACTLY t seconds

    need = max(dx, dy);

    Case 1 : t < need
    IMPOSSIBLE
    You cannot reach that fast.

    Case 2 : t >= need  
    usually possible because you can waste time:

    go left
    come right
    or
    up then down

    BUT One Special Edge Case
    If start and finish are SAME:

    sx == fx && sy == fy

    and:
    t == 1
    Answer is FALSE.

    Why?

    Because every second you MUST move.

    You cannot stay in same cell.

    After 1 move you are forced to leave the cell.

    So impossible.




*/
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
         if (sx == fx && sy == fy) {
            return t != 1;
        }

        int dx = abs(fx-sx);
        int dy = abs(fy-sy);

        return max(dx,dy) <= t;
    }
};
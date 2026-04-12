/*

future HINTS :

    “Minimum total distance” -> Greedy OR DP
    “You have TWO fingers” -> Recursion
    “You cannot reorder characters” -> sorting / greedy by rearrangement ❌
    “which finger types each character”
        At each index → I have 2 choices

English uppercase letter is located at some coordinate.

the letter 'A' is located at coordinate (0, 0),
the letter 'B' is located at coordinate (0, 1), 
the letter 'P' is located at coordinate (2, 3) 
and the letter 'Z' is located at coordinate (4, 1)


Given the string word, 
return the minimum total distance to type such string using only two fingers.

distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

when did distance is minimum???????????????

first 2 charchaters are absloutly free............

how to know the corridnate of an charcter???????

should i make array : pair<int,int> 
    where {x,y}

yea i guess this is the only option we have 

row = 0
col = 0
for(0 -> 26)
    a : {row,col++}
    if(col == 5){
        row++;
        col = 0;
    }

now we have array of corrdinates 

C : {2 ,2}
K : {1 ,4}

1 + 3 = 4

from this we can see we cannot chpose charchters randomly..........

First move is FREE
Both fingers start anywhere → cost = 0

CANNOT reorder characters.....

word = "CAKE"
must type:
C → A → K → E


Greedy (nearest finger) fails.... in future

At every step:
    we have 2 choices:

Use finger 1
Use finger 2

So problem =
    decision making at each step

This screams: DP (Dynamic Programming)

    we have to try all possiblites........

    -------------RECURSION-------------

    states ?????????????????

    solve(index,f1,f2) = Minimum cost to type from index i to end, 

        finger1 is at f1
        finger2 is at f2


at start :
    f1 = -1
    f2 = -1

means finger not placed yet → cost = 0

how many choices are there???????

At index i, you need to type: word[i]

Option 1: 
        Use finger1

cost: distance(f1, word[i])

then:
    solve(i+1, word[i], f2)



Option 2: 
        Use finger2

cost : distance(f2, word[i])

then:
    solve(i+1,f1,word[i])


BASE CASE????????
    string get exausted ????????

    if(i == n) return 0;


NOW COMES TO DISTANCE PART.........

If finger not used yet:

    if (f == -1) return 0;

else 

    calculate distance 


how to calculate distance???
    we need row and col of word[i] and finger position.........


        A B C D E F
        G H I J K L
        M N O P Q R
        S T U V W X
        Y Z

Total letters = 26
Layout is 6 columns per row

4 full rows → 6 × 4 = 24
Last row → 2 letters (Y, Z)

Coordinate Formula:

    row = (ch - 'A') / 6;
    col = (ch - 'A') % 6;

example  :

    'F'
5 / 6 = 0
5 % 6 = 5
 (0, 5)

distance function :
    
    int x1 = a / 6, y1 = a % 6;
    int x2 = b / 6, y2 = b % 6;

    return abs(x1 - x2) +  abs(y1 - y2);

    GIVE TLE -> (24/55)

add memoization................

dp size and variables??????????

i -> 0 to n-1


    ----IMPORTANT---
f1, f2 ->
    0 to 25 OR -1
SO, -1 to 25

but dp dosent have negative index so, map to 0..26
-1 → 26
0–25 → same


*/
class Solution {
public:
    //distance function
    int dist(int a, int b) {
        // 26 → -1
        if (a == 26) return 0; // not used yet

        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int i, int f1, int f2, string &word,
              vector<vector<vector<int>>> &dp) {
        
        if (i == word.size()) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        // use finger1
        int cost1 = dist(f1, curr) + solve(i + 1, curr, f2, word, dp);

        // use finger2
        int cost2 = dist(f2, curr) + solve(i + 1, f1, curr, word, dp);

        return dp[i][f1][f2] = min(cost1, cost2);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(27, vector<int>(27, -1))
        );

        // 26 → -1
        return solve(0, 26, 26, word, dp);
    }
};
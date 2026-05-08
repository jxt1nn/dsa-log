/*
You are given an integer array nums of length n.

You start at index 0,
and your goal is to reach index n - 1.

From any index i,
you may perform one of the following operations:


--------------------------------------------------
OPERATION 1 : ADJACENT MOVE
--------------------------------------------------

Jump to:

i + 1
or
i - 1

if inside bounds.


--------------------------------------------------
OPERATION 2 : PRIME TELEPORTATION
--------------------------------------------------

If nums[i] is a prime number p,

then you may jump to ANY index j
such that:

nums[j] % p == 0


--------------------------------------------------
STEP 1 : WHAT IS THE QUESTION ASKING?
--------------------------------------------------

Return the MINIMUM number of jumps.

Whenever you see:

minimum jumps
minimum moves
minimum operations
shortest path

immediately think:

BFS

because BFS gives shortest path
in an unweighted graph.


--------------------------------------------------
STEP 2 : FIND THE STATE
--------------------------------------------------

What changes during the game?

Your current INDEX.

So:

each index = one node/state


--------------------------------------------------
STEP 3 : FIND ALL POSSIBLE MOVES
--------------------------------------------------

From index i:

NORMAL MOVES:

i -> i+1
i -> i-1


TELEPORT MOVES:

If nums[i] is prime = p

then:

i -> every index j
where nums[j] % p == 0


--------------------------------------------------
STEP 4 : REALIZE THE HIDDEN GRAPH
--------------------------------------------------

The array is secretly a graph.

Each index = node

Allowed jumps = edges


--------------------------------------------------
STEP 5 : EXAMPLE
--------------------------------------------------

nums = [2,4,6,3,9]

Index 0 has value 2.

2 is PRIME.

So from index 0:

can go to index 1
because 4 % 2 == 0

can go to index 2
because 6 % 2 == 0

Also adjacent move:

0 -> 1

So node 0 has multiple edges.


--------------------------------------------------
STEP 6 : WHY BFS?
--------------------------------------------------

Every jump costs exactly 1.

No weighted edges.

Shortest path in unweighted graph:

BFS


--------------------------------------------------
STEP 7 : NAIVE APPROACH
--------------------------------------------------

For every prime index:

scan the whole array
to find divisible numbers.

This becomes slow.


--------------------------------------------------
STEP 8 : IMPORTANT OPTIMIZATION
--------------------------------------------------

We repeatedly need:

"all indices divisible by p"

So preprocess:

prime factor -> list of indices


Example:

2 -> [0,1,2]
3 -> [2,3,4]
5 -> [...]


Now teleportation becomes fast.


--------------------------------------------------
STEP 9 : HOW TO BUILD THIS MAP
--------------------------------------------------

Traverse the array.

For every nums[i]:

find all factors of nums[i]

store:

factor -> index


Example:

nums[i] = 12

Factors:

2
3

Store:

2 -> i
3 -> i


--------------------------------------------------
STEP 10 : BFS FLOW
--------------------------------------------------

Start BFS from index 0.

For current index:

1. Try adjacent moves
2. If nums[i] is prime:
      visit all divisible indices

Mark visited indices
so we do not revisit them.


--------------------------------------------------
STEP 11 : IMPORTANT OPTIMIZATION
--------------------------------------------------

Suppose prime = 2

Once we already used teleportation for 2,
we should NEVER process it again.

Otherwise same indices repeat again and again.

So keep:

usedPrime[p]


--------------------------------------------------
STEP 12 : FINAL THINKING PROCESS
--------------------------------------------------

minimum jumps
    ->
shortest path

indexes
    ->
graph nodes

allowed jumps
    ->
graph edges

all edges cost 1
    ->
BFS


--------------------------------------------------
CORE INTUITION SUMMARY
--------------------------------------------------

The problem is secretly:

Build a graph of indices
and find shortest path
from index 0 to index n-1

using BFS.

*/
class Solution {
public:

    // check prime
    bool isPrime(int n) {

        if(n < 2) return false;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        // factor -> indices divisible by factor
        unordered_map<int, vector<int>> mp;

        // build map
        for(int i = 0; i < n; i++) {

            int x = nums[i];

            // store all prime factors
            for(int f = 2; f * f <= x; f++) {

                if(x % f == 0) {

                    mp[f].push_back(i);

                    while(x % f == 0) {
                        x /= f;
                    }
                }
            }

            // remaining prime factor
            if(x > 1) {
                mp[x].push_back(i);
            }
        }

        queue<int> q;
        vector<int> vis(n, 0);

        // to avoid reprocessing same prime
        unordered_set<int> usedPrime;

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int i = q.front();
                q.pop();

                // reached end
                if(i == n - 1) {
                    return steps;
                }

                // adjacent left
                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // adjacent right
                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                // teleportation
                int val = nums[i];

                if(isPrime(val) && !usedPrime.count(val)) {

                    usedPrime.insert(val);

                    for(int nextIndex : mp[val]) {

                        if(!vis[nextIndex]) {

                            vis[nextIndex] = 1;
                            q.push(nextIndex);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
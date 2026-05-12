/*

tasks[i] = [actual, minimum]

actual   = energy spent to finish task
minimum  = minimum energy required to START task

Example:

task = [10,12]

current energy = 11
cannot start because 11 < 12

current energy = 13
can start

after finishing:
13 - 10 = 3 energy left


--------------------------------------------------

GOAL:
Find minimum initial energy required
to finish all tasks in some order.


--------------------------------------------------

INTUITION

We can perform tasks in ANY order.

Important observation:

(minimum - actual)

tells us how much EXTRA BUFFER this task needs.

Large buffer tasks are dangerous to do later,
because after doing other tasks our energy decreases.

So:

tasks with larger (minimum - actual)
should be done FIRST.


--------------------------------------------------

SORTING

sort by:

(minimum - actual) descending


Example:

[1,3]   -> diff = 2
[10,11] -> diff = 1

[1,3] should come first.


--------------------------------------------------

SIMULATION

Start:

energy = 0
answer = 0

For every task:

1. Check if current energy is enough to START.

if(energy < minimum)

we must add extra energy.

needed = minimum - energy

answer += needed
energy += needed


2. Finish the task

energy -= actual


--------------------------------------------------

WHY THIS WORKS

We only add energy when absolutely necessary.

And because high-buffer tasks are completed early,
we avoid situations where we suddenly need
a huge amount of extra energy later.


--------------------------------------------------

TIME COMPLEXITY

Sorting: O(n log n)
Traversal: O(n)

Total: O(n log n)

*/
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(),
        [&](vector<int>& a, vector<int>& b) {

            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0;
        int energy = 0;

        for(auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            // not enough energy to start
            if(energy < minimum) {

                int need = minimum - energy;

                ans += need;
                energy += need;
            }

            // finish task
            energy -= actual;
        }

        return ans;
    }
};
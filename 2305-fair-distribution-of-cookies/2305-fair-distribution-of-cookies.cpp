/*

cookies[i] → number of cookies in each bag
k → number of children

Rules:
Each bag must go entirely to one child (no splitting)
Every bag must be assigned

What is "unfairness"?
Unfairness =  maximum cookies any one child gets

So if distribution is:

Child 1 → 5 cookies
Child 2 → 10 cookies
Child 3 → 7 cookies

Unfairness = 10 (max of all)

Distribute bags so that no child gets overloaded
So we are trying to:

“Balance the distribution as evenly as possible”

    We are not minimizing sum
    We are minimizing the maximum   

“Minimize the maximum” problem

Each bag has to go to one of the k children
    So for each bag:
        we have k choices

try all possible ways....................

    -------------RECURSION-------------

cookies = [8, 15, 10]
k = 2
try possibilities:

Option 1:
    Child A → 8 + 15 = 23
    Child B → 10
     max = 23 
Option 2:
    Child A → 8 + 10 = 18
    Child B → 15
    max = 18  (better)

Each bag → try assigning to every child
Explore all distributions

    AFTER MAKING RECUSRION TREE IT WILL GET MORE CLEAR 

“Put each bag into one of k buckets and try all possibilities, while tracking the worst-loaded bucket.”

        If current max already ≥ GLOOBAL best answer → stop exploring 

k = 3 children
current distribution = [0, 0, 0]

Take bag 8:
→ [8,0,0]
→ [0,8,0]
→ [0,0,8]

Next bag 15:
→ try adding to each child again
    means apply same logic but with index+1 element 


how to write recursion..????????

their are levels in recusrion 
    like how many elmenet presrnt in array is our number of levels........

What state do I need to track?
“I need to know how many cookies each child has”?????????

SOOOOOOOOOOOOO create:

children[i] = total cookies of child i

function(index):
    try all children
        assign bag
        go to next index
        undo assignment

BASE CASE?????????????????????????????  

    if (index == cookies.size())
        track maximum elemnet of childern array 
then :

-> ans = min(ans, current_max)

and one more thing if at any point array elemnent gets bigger than GLOBAL MAX 

“If already worse, don’t continue”

if current child load < ans:
    continue recursion



**/
class Solution {
public:
    int ans = INT_MAX;

    void solve(int index, vector<int>& cookies, vector<int>& children) {
        // (all bags assigned)
        if (index == cookies.size()) {
            int maxi = 0;
            for (int x : children) {
                maxi = max(maxi, x);
            }
            ans = min(ans, maxi);
            return;
        }

        // assigning current bag to each child
        for (int i = 0; i < children.size(); i++) {

            // assign
            children[i] += cookies[index];

            if (children[i] < ans) {
                solve(index + 1, cookies, children);
            }

            // (backtrack)
            children[i] -= cookies[index];

        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        solve(0, cookies, children);
        return ans;
    }
};
/*

    IMPORTANT PATTERN

    Whenever you see:

    from index i you can jump to ...

    start thinking:

    “Indices = graph nodes”

    Then ask:

    longest path? → DFS + DP
    minimum steps? → BFS
    all possible paths? → Backtracking


    --------------------------------------------------


    STATE

    we are standing at index i


    --------------------------------------------------


    CHOICES / MOVES

    from index i we can jump:

    LEFT:
    i-1, i-2, ..., i-d

    RIGHT:
    i+1, i+2, ..., i+d


    BUT jump is allowed only if:

    arr[i] > arr[j]

    means:
    we can only jump to smaller values


    --------------------------------------------------


    IMPORTANT BLOCKING CONDITION

    while moving toward j

    every element between i and j
    must also be smaller than arr[i]

    meaning:

    if we encounter:

    arr[k] >= arr[i]

    then movement stops completely
    in that direction


    example:

    arr = [8,5,3,9,2]

    from 8:

    can go:
    5
    3

    cannot cross 9

    so cannot reach 2 either


    --------------------------------------------------


    GOAL

    find maximum indices visited


    we can start from ANY index


    --------------------------------------------------


    IMPORTANT OBSERVATION

    jumps always go:

    bigger -> smaller

    therefore:

    cycle is impossible


    because if:

    arr[i] > arr[j]

    then j can never come back to i


    so graph becomes:

    DAG (Directed Acyclic Graph)


    --------------------------------------------------


    WHAT TYPE OF QUESTION?

    question is asking:

    maximum path length

    keywords:
    maximum
    longest
    best possible

    => DFS + Memoization


    --------------------------------------------------


    WHY DFS + DP?

    from every index:

    we explore all valid jumps

    then ask:

    what is the best answer from there?


    same subproblems repeat

    example:

    dfs(3)
    may get called from many indices

    so memoization needed


    --------------------------------------------------


    DFS MEANING

    dfs(i)

    means:

    maximum indices we can visit
    starting from index i


    --------------------------------------------------


    BASE THINKING

    minimum answer always:

    1

    because current index counts itself


    so:

    int ans = 1;


    --------------------------------------------------


    RECURSION THINKING

    if we can jump:

    i -> j

    then problem becomes:

    best answer starting from j

    therefore:

    1 + dfs(j)


    transition:

    ans = max(ans, 1 + dfs(j))


    --------------------------------------------------


    LEFT EXPLORATION

    for(int j = i - 1; j >= max(0, i - d); j--)

    try all left jumps within distance d


    if(arr[j] >= arr[i])

    break immediately


    WHY BREAK?

    because taller/equal element blocks
    all further jumps too


    --------------------------------------------------


    RIGHT EXPLORATION

    for(int j = i + 1; j <= min(n - 1, i + d); j++)

    same logic


    if(arr[j] >= arr[i])

    break


    --------------------------------------------------


    WHY NO VISITED ARRAY?

    visited array is used for:

    cycle prevention

    but cycles cannot exist here

    because jumps always go:

    bigger -> smaller


    we WANT multiple paths
    to reuse:

    dfs(i)

    so:

    use dp
    not visited


    --------------------------------------------------


    DP MEANING

    dp[i]

    means:

    already computed answer for dfs(i)


    if(dp[i] != -1)

    return stored answer


    --------------------------------------------------


    TIME COMPLEXITY

    every index explores:

    at most d left
    at most d right

    therefore:

    O(n * d)


*/
class Solution {
public:

    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {

        // already computed
        if(dp[i] != -1)
            return dp[i];

        int n = arr.size();

        // minimum answer
        // current index itself
        int ans = 1;

        // ---------------- LEFT ----------------

        for(int j = i - 1; j >= max(0, i - d); j--) {

            // blocked
            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        // ---------------- RIGHT ----------------

        for(int j = i + 1; j <= min(n - 1, i + d); j++) {

            // blocked
            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 1;

        // we can start from any index
        for(int i = 0; i < n; i++) {

            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};
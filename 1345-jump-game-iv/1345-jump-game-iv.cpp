/*

    Important Pattern

        Whenever you see:

        from index i you can move to ...

        start thinking:

    “Indices = graph nodes”

    Then ask:

        Any path exists? → DFS/BFS
        Minimum steps? → BFS
        Explore all paths? → Backtracking/DFS
    
    
    STATE

    we are standing at an index


    CHOICES / MOVES

    from index idx we can go:

    1. idx + 1
    2. idx - 1
    3. any index j
    where arr[idx] == arr[j]


    GOAL

    reach last index

    idx == n - 1


    WHAT TYPE OF QUESTION?

    question is asking:

    minimum number of steps

    keywords:
    minimum
    shortest path
    least moves

    => BFS


    WHY BFS?

    because BFS explores level by level

    first time we reach last index
    will always be minimum steps


    GRAPH THINKING

    each index behaves like graph node

    neighbors of idx:

    {
    idx + 1,
    idx - 1,
    all same value indices
    }


    IMPORTANT OBSERVATION

    same values can create many edges

    example:

    [7,7,7,7,7]

    from one index
    we can jump to all others


    OPTIMIZATION

    store:

    value -> all indices

    unordered_map<int, vector<int>> mp;


    example:

    7 -> [0,1,2,3,4]


    WHY CLEAR THE VECTOR?

    after processing all indices of a value once

    we never need them again

    otherwise:
    same neighbors get processed repeatedly

    causing TLE


    BFS FLOW

    start BFS from index 0

    for every popped index:

    1. check idx + 1
    2. check idx - 1
    3. check all same value indices

    push unvisited neighbors into queue


    WHEN ANSWER IS FOUND?

    first time we reach:

    idx == n - 1

    return current BFS level (steps)


    TIME COMPLEXITY

    O(n)

    because every index is visited once

    and same-value groups are cleared after use

*/
class Solution {
public:

    int minJumps(vector<int>& arr) {

        int n = arr.size();

        // already at last index
        if(n == 1)
            return 0;

        // value -> all indices having that value
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // BFS
        queue<int> q;

        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            // process one BFS level
           for(int i=0;i<size;i++) {

                int idx = q.front();
                q.pop();

                // reached last index
                if(idx == n - 1)
                    return steps;

                // neighbors

                // 1. i + 1
                if(idx + 1 < n &&
                   !vis[idx + 1]) {

                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // 2. i - 1
                if(idx - 1 >= 0 &&
                   !vis[idx - 1]) {

                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // 3. same value indices
                for(int next : mp[arr[idx]]) {

                    if(!vis[next]) {

                        vis[next] = 1;
                        q.push(next);
                    }
                }

                // IMPORTANT:
                // clear to avoid revisiting same group again
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};
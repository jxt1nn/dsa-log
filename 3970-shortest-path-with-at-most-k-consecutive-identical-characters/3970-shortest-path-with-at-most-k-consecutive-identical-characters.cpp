/*
    We have:

        Directed Weighted Graph
        n nodes numbered from 0 to n-1

        edges[i] = {u, v, w}

        means:

            u ----(w)---> v

    Also given:

        labels string

            labels[i]

        represents character assigned to node i

    Example:

            Node : 0 1 2 3
            Label: a a b b

    -------------------------------------------------

    What is the task?

        Find minimum cost path

            from node 0
                    to
            node n-1

    BUT with an extra condition:

        Along the chosen path,

        the label string formed by visited nodes

        must contain

            at most k consecutive identical characters

    -------------------------------------------------

    Example:

        Path:

            0(a) -> 1(a) -> 2(b) -> 3(b)

        Label string:

            aabb

        Consecutive groups:

            aa -> length 2
            bb -> length 2

        Maximum streak = 2

        Valid if:

            k >= 2

    -------------------------------------------------

    Invalid Example:

        Path:

            0(a) -> 1(a) -> 2(a) -> 3(b)

        Label string:

            aaab

        Consecutive group:

            aaa -> length 3

        Invalid if:

            k = 2

    -------------------------------------------------

    Key Observation:

        This is NOT a normal shortest path problem.

        Why?

        Because reaching the same node can mean
        different things.

    Example:

            labels:

                a a b a

        Reach node 3 through:

            Path A:

                a -> a -> a

                current streak = 3

        Reach node 3 through:

            Path B:

                a -> b -> a

                current streak = 1

        Both are at same node.

        But future choices are different.

        Therefore:

            node alone is NOT enough state.

    -------------------------------------------------

    Ask:

        What information from the past
        affects future decisions?

    We do NOT care about:

        whole path string

    We ONLY care about:

        current consecutive streak length

    Therefore state becomes:

        (node, streak)

    -------------------------------------------------

    Meaning of state:

        dis[u][cnt]

    means:

        Minimum cost to reach node u

        while ending with

            cnt consecutive copies

        of character labels[u]

    -------------------------------------------------

    Example:

        Path labels:

            a b b a a

        Current node label:

            a

        Ending streak:

            aa

        Therefore state:

            (currentNode, 2)

    -------------------------------------------------

    Why Dijkstra?

        Edge weights exist.

        Need minimum total cost.

        Therefore:

            Dijkstra

    -------------------------------------------------

    Initial State:

        Start at node 0

        Path:

            only node 0

        Current streak:

            1

        Cost:

            0

        So:

            dis[0][1] = 0

            push:

                {0, 0, 1}

            into pq

    -------------------------------------------------

    PQ State:

        {distance, node, streak}

    Example:

        {15, 4, 2}

    means:

        Cost = 15

        Reached node 4

        Current streak = 2

    -------------------------------------------------

    While processing node u:

        Try every neighbour v

    -------------------------------------------------

    Most Important Transition:

        If labels stay same:

            streak continues

        If labels change:

            streak restarts

    Code:

        if(labels[v] == labels[u])

            newStreak = streak + 1

        else

            newStreak = 1

    -------------------------------------------------

    Example:

        Current:

            aa

        streak = 2

        Next label:

            a

        New:

            aaa

        newStreak = 3

    -------------------------------------------------

    Example:

        Current:

            aa

        Next label:

            b

        New:

            aab

        newStreak = 1

    -------------------------------------------------

    Validity Check:

        if(newStreak > k)

            skip

    Why?

        Constraint violated.

        This path can never be part
        of the answer.

    -------------------------------------------------

    Relaxation:

        If

            currentCost + edgeWeight

        improves

            dis[v][newStreak]

        then update.

    -------------------------------------------------

    Why can we return immediately
    when node == n-1 ?

        Dijkstra property:

            First popped state

            always has minimum distance.

        Therefore first valid state
        reaching destination

        is the answer.

    -------------------------------------------------

    Pattern To Remember:

        Shortest Path
            +
        Extra Path Constraint

        =>
        Dijkstra on Expanded States

    -------------------------------------------------

    Expanded State Here:

        (node, consecutiveCharacterCount)

    Not:

        (node)

    That's the entire trick of the problem.

*/
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &x : edges){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<vector<long long>> dis(n,vector<long long>(k+1,LLONG_MAX));

        priority_queue<tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<tuple<long long,int,int>>> pq;

        int ch = s[0] - 'a';

        dis[0][1]= 0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d,u,cnt] = pq.top();
            pq.pop();

            if(d >dis[u][cnt]) continue;

            if(u == n -1) return d;

            for(const auto& edges : adj[u]){
                int v = edges.first;
                int wei = edges.second;
                
                int ncnt = s[v] == s[u] ? cnt+1 : 1;

                if(ncnt > k) continue;

                if(d + wei < dis[v][ncnt]){
                    dis[v][ncnt] = d + wei;
                    pq.push({d+wei,v,ncnt});
                }
            }
        }
        return -1;
    }
    
};
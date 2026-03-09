/*
    undirected weighted graph.....

    number of ways to reach n-1

    n-1 is our final destinationn
    and starting position is 0

    Return the number of ways
        you can arrive at your destination in the shortest amount of time. 

    okay so we have to count the number of ways with shortest distance......

    like we get 8 and its count is 2

    but in future we incounter 7 so we restart the count from 0

    how can we do this?????????

    not best but yea 
    //     prevShortDistance
    //     count 

    //     if (newDist < prevShortDistance){
    //         count = 1;
    //         prevShortDistance = newDist 
    //     }

    // this is  the normal dijkstra algo problem 

    //     bocz we need to find the shortest distance in weighted graph

    // what we need:

    //     prevShortDistance
    //     count 
    //     pq (min-heap) -> {time,node}
    //     distVector

    // sourc location = (0,0)

    // relaxtion :
    //     if(tem + edw < dist[node]){
    //         push into pq
    //         dist[node] = tem + edw
    //     }
    
    // this is if we found smaller one :
    //     if(node == n-1){
    //         if (newDist < prevShortDistance){
    //             count = 1;
    //             prevShortDistance = newDist 
    //         }
    //         else if(newDist == prevShortDistance{
    //             count++;
    //         }
    //     }   
    


    ACTUAL APPROACH

        what we do previously we only calculate ways for n-1

    but this is not a good practice 
        we have to find for every node

    so how can we do this?????????

    “if we encounter 7 after 8, we reset count”
        In Dijkstra, that situation never happens if implemented correctly.

    Because Dijkstra processes nodes in increasing order of distance using a min-heap.
    So once you pop a node with distance d,
    you are guaranteed that this is the shortest possible distance to that node.

    So we don’t track prevShortDistance manually.

    dist[i] → shortest time to reach node i
    ways[i] → number of shortest ways to reach node i
        

    While relaxing edges in Dijkstra: 

    The dynamic programming aspect comes from how we update the ways array. 
    For each node, 
    the number of ways to reach it is the sum of the ways to reach all its predecessors in the shortest path.

        Case 1: Found strictly shorter path

    if(newDist < dist[node]){
        dist[node] = newDist
        ways[node] = ways[current]
        push to pq
    }

    why we do this : ways[node] = ways[current]

    A -> B -> C

    if their are 3 ways to reach B 

    SO, next node is C from B so their is also atleast 3 ways to reach C

        Case 2: Found another shortest path
    
    if(newDist == dist[neighbor]){
        ways[neighbor] += ways[current]
        ways[neighbor] %= MOD
    }

    Case 1: Better distance
        We REPLACE:
        ways[neighbor] = ways[node]
        Because old paths are useless.

        Case 2: Equal distance
        We ADD:
        ways[neighbor] += ways[node]

        Because we found another shortest route.
    
    Initialize:

        dist[i] = INF
        ways[i] = 0

        dist[0] = 0
        ways[0] = 1

        Use minHeap storing {distance, node}

        While heap not empty:
            pop (time, node)

            if time > dist[node]:
                continue

            for each (neighbor, weight):
                newDist = time + weight

                if newDist < dist[neighbor]:
                    dist[neighbor] = newDist
                    ways[neighbor] = ways[node]
                    push (newDist, neighbor)

                else if newDist == dist[neighbor]:
                    ways[neighbor] += ways[node]
                    ways[neighbor] %= MOD

        Return ways[n-1]



**/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = LLONG_MAX;
        const int MOD = 1e9 + 7;
        
        // Adjacency list: {neighbor, time}
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int t = r[2];
            
            adj[u].push_back({v, t});
            adj[v].push_back({u, t}); // bi-directional
        }
        
        // Distance and ways array
        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);
        
        // Min heap: {time, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            // Skip outdated entries
            if(time > dist[node]) continue;
            
            for(auto &[adjNode, wt] : adj[node]) {
                long long newDist = time + wt;
                
                // Found shorter path
                if(newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];  // inherit ways
                    pq.push({newDist, adjNode});
                }
                // Found another shortest path
                else if(newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1] % MOD;
    }
};
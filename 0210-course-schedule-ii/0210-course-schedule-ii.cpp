        /*
    To take course ai, you must first take bi
        bi → ai

    That is a directed edge.

    So the problem is actually:
        You are given a directed graph
    Check if it is possible to complete all nodes

    What makes it impossible?
        When can you NOT finish courses?
    
    0 needs 1   0 → 1
    1 needs 0   1 → 0       

    This is a cycle. You can’t start anywhere.

    So the real question becomes:
        Does the directed graph contain a cycle?


    This problem is about:

        Directed graph
        Prerequisite
        Order
        Can we finish all?

    This screams:
        Topological Sort or Cycle Detection in Directed Graph

    DFS (Cycle Detection)  
    OR  
    BFS (Kahn’s Algorithm - Topological Sort)

    lets do topo sort by BFS 

    Steps:
        Make adjacency list
        Compute in-degree of every node
        Push nodes with in-degree = 0 into queue
        Process them
        Reduce in-degree of neighbors
        If at the end:
            You processed all nodes → ✅possible
            You didn’t → ❌ cycle exists

        if possible return stored topo sort
        else return EMPTY STRING.......
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {    
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj[prereq].push_back(course);  // edge prereq -> course
            indegree[course]++;             // increase indegree
        }
        
        // Push all nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        //BFS
        int count = 0;
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If all courses processed → no cycle
        if(ans.size() == numCourses) return ans;
        return {};
    }
};

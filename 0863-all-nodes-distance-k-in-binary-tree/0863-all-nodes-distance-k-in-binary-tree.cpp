/**

    isn't easy????????????????

    just start bfs from target node and return kth level all nodes

    ohhh LOL 
    thiss is not a graph XDD

    we can go only left and right............


    but can we make graph from tree????????
    then do bfs from target.......

    so how can we make graph from tree????

    what we need from a node????
    node can go left and right 
                            but not parent (UP)

    Tree is not naturally a graph, because:
    No parent pointer
    Can't go upward

   Tree (one-way)
   parent
   ↓
   child

    Graph (two-way)
    parent ↔ child

    we dont need the full adjancy list 

    Because:

    child already knows left/right
    we only need missing link = parent

    step 1. Create map :
    unordered_map<TreeNode*, TreeNode*> parent;

    Step 2: Traverse tree
    Use BFS (easy) or DFS


    Step 3: Fill mapping
    Whenever you see:

    node->left → parent is node
    node->right → parent is node

    now we have all links for a node 
        left,right,parent(up)

    now we can do simple BFS from target node.......

    what we need for this type of bfs this is not normal tree bfs

    queue(source)
    visited dataStructure (set,map)










 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    //{node,parent}
    void UP(TreeNode* root){
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            int siz = q.size();

            for(int i =0;i < siz;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        UP(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);
        int level = 0;

        while(!q.empty()){
            int siz = q.size();
            
            if(level == k) break;

            for(int i=0;i < siz;i++){
                TreeNode* node = q.front();
                q.pop();

                // count(...) == 1 → present (visited)
                // count(...) == 0 → not visited
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            level++;
        }
        vector<int> ans;

        while(!q.empty()){
            TreeNode* node = q.front();
            ans.push_back(node->val);
            q.pop();
        }

        return ans; 
    }
};
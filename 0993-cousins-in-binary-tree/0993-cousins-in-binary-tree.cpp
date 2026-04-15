/**

what is cousins????????????

if 2 nodes are on same level but they have differnet parts they are cousins.....

how to check x and y are cousins.........!!!!!!!!

simple BFS.......

we should check that x and y are same level or not?????????

if they both are present in queue at same time they are on same level.......

so we can do one thing push({node,parent}) in queue 
and after each level check if x and y present or not with differnt parenets

what we need to check they are cosuise or not???

depth : should be same 
parent : should be differnt

While doing BFS:
    For each node:
    Store (node, parent)
At each level:
    Check if x and y are found


*/
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q; // node, parent
        q.push({root, NULL});

        while (!q.empty()) {
            int size = q.size();
            TreeNode* parentX = NULL;
            TreeNode* parentY = NULL;

            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) parentX = parent;
                if (node->val == y) parentY = parent;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // after one level
            if (parentX && parentY) {
                return parentX != parentY;
            }
            if (parentX || parentY) {
                return false;
            }
        }

        return false;
    }
};
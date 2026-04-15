/**
    is it same as maximum depth??????
        1 + max(left,right)?????????

opposite of it???????????????

1 + min(left,right)???????

from root to leaf means 

we dont need minimum depth from each node only one last tiee..........

we return normal depth to parent 
how????????????


we are not calculating left and right correctly.............

we go left calculate its depth.................

how?????????


can we calculate depth of left 
    then right???

then return the answer???????????

Case 1: If node is NULL

→ depth = 0

Case 2: If node is a leaf

→ depth = 1

Case 3: If one child is missing

if left == NULL → go right
if right == NULL → go left

👉 You are forced to go that path

Case 4: If both children exist
depth = 1 + min(left_depth, right_depth)


❌ Common mistake (avoid this)
return 1 + min(minDepth(root->left), minDepth(root->right));
🚫 This is WRONG because:

It treats NULL as depth 0
Gives incorrect answer when one child is missing


BFS is more intutive..........

return depth as soon as we encounter first leaf node.........
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check if it's a leaf node
                if (node->left == NULL && node->right == NULL) {
                    return depth;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            depth++; // move to next level
        }

        return depth;
    }
};
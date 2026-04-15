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

*/
class Solution {
public:
    int solve(TreeNode* node){
        if(node == NULL) return 0;

        /// If left subtree is NULL, ignore it and go right
        if(node->left ==  NULL){
            return 1 + solve(node->right);
        }
        // If right subtree is NULL, ignore it and go left
        if(node->right == NULL){
            return 1 + solve(node->left);
        }
         // If both children exist, take minimum
        return 1 + min(solve(node->left),solve(node->right));
    }
    int minDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};
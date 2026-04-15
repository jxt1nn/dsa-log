/**

maximum depth 
    either left or right 

    1 + max(left,right)


how to write code

leaf node : 0

go left 

go right 

rteurn 1 + max(left,right)


*/
class Solution {
public:
    int solve(TreeNode* node){
        if(node == NULL) return 0;

        //go left
        int left = solve(node->left);
        // go right
        int right = solve(node->right);

        return 1 + max(left,right);
    }
    int maxDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};
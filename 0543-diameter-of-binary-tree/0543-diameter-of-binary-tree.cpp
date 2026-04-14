/*

what is the diameter??????????

left depth + right depth + 1

how to calculate this for each node???????


is we calculating the number of nodes?????????

we calculate as:
    1 + left + right

but we send to parent??????????

we return 1 + max(left,right)

and what we return as global answer????
return ans



"diameter through this node = left + right"

*/
class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        ans = max(ans,left + right);

        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
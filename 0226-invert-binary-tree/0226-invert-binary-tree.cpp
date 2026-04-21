/**
    how to invert a trer????????????

    root always be same 

    just change the left and right child...........

    how can we do this for 3 node tree??????

    left 
    right 

    just swap left and right

    how can we do this thing in bigg tree

    just do the same for every subtree 

    swap(left,right)

    then call recursion 

*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        swap(root->left,root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
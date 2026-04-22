/**
    just find preorder traversal then convert it 

    how to convert???????????
    IN-PLACE................
    
    means we cannot make extra preorder array then converr it..........

    how to do this in-plavce 

    BY OBERSERVING we can see every thing on right........

 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Step 1: flatten left & right
        flatten(root->left);
        flatten(root->right);

        // Step 2: store right subtree
        TreeNode* temp = root->right;

        // Step 3: move left subtree to right
        root->right = root->left;
        root->left = NULL;

        // Step 4: go to end of new right chain
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        // Step 5: attach old right subtree
        curr->right = temp;
    }
};
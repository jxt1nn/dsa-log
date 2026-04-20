/**

    what are the casses for LCA????????????

    both on left 
    both on right 
    one left and one right

    if both one same side 
    return the first one seen 

    and if both on differnt side root will be the answer
    
    we can do this for every subtree 

    what can be the abse case?????????

    if(node == NULL || node == p || node == q){
        return node;
    }

    their are 3 case?????????????

    -> differnt sides:

    if(left != NULL && right != NULL){
        return root;
    }

    -> found on left subtree :
    if(left != NULL){
        return left;
    }

    ->found on right subtree:
     if(right != NULL){
        return right;
     }

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Base case
        if (root == NULL || root == p || root == q)
            return root;

        //Search in left and right
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // differnt side
        if (left != NULL && right != NULL)
            return root;  // split point → LCA

        // both are on same side
        if (left != NULL)
            return left;

        return right;
    }
};
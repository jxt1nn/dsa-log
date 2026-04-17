/** 

    how calculate maximum sum???????????????????

    what i am thinking.................

    take one GLOBAL MAXIMUM 
    and this feels kinda diamter of binary tree problem vibe 543


    bcoz if we have left and right in children node we can go either left of childern
    Or 
    right of children 
    bcoz path cannot spilt in 2 ways..........

    on what bases we take path??????? SUM

    calculate sum of left tree 
    right tree 

    
    return node->val + max(left,right)
    this is return to upper node 

    but what we save as global maximum 
    left + node + right(full path)


    but here is a thing we should avoid negative path   
    left = max(0,node->left)
    right = max(0,node->right)
    Possible paths at a node:

    1️⃣ Only left side
    left → node
    2️⃣ Only right side
    node → right
    3️⃣ Through node (IMPORTANT)
    left → node → right


*/
class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // path passing through this node
        maxSum = max(maxSum, left + right + root->val);

        // return one side
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
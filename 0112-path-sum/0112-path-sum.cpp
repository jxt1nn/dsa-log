/**

it should be root to leaf path
    not node's sum..............

we dont know what comes next???????????????????
    if we select now they might create problem in ftutue............

"root-to-leaf"

am assuming this is start from root and go either left right

bool

when did we return true??????????

whenever we get true...............

so when we get our first true we return GLOBAL true also

and if we doesnt get true in all possiblites
    then we return false.........


how to code this???????????

leaf node : 0

go to a node and decrease that many points from target.............

and if target beacme less tgan 0 return false

and when ever taregt == 0 return true.......match condition........
    || -> condition


path should be root to leaf

what is leaf node?????????
    no left AND right

biggest confusion leaf node == NULL this is WRONG





*/
class Solution {
public:
    bool solve(TreeNode* node,int t){
        //leaf node :  no left AND right
        if(node == NULL) return false;
        if(node->left == NULL && node->right == NULL){
            if(t - node->val == 0){
                return true;
            }
            return false;
        }

        return solve(node->left,t-node->val) 
            || solve(node->right,t-node->val); 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        bool ans = solve(root,targetSum);
        return ans;
    }
};
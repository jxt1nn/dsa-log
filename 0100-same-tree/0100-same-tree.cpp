/*

we have root of both of the trees

then go left and repeat same then we cannot go left go right then


how to code this???????

solve(root1,root2) 

when return true ????????????
when function is complete??????????

when to treturn false??????????

immedatailly if we found 1 false


base case????????
if(val1 != val2) return false.........

recursion call????????

return left && right 

*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if go to leaf node
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->val != q->val) return false;

       return isSameTree(p->left,q->left) 
            && isSameTree(p->right,q->right); 
    }
};
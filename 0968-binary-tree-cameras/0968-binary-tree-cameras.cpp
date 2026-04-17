/**

    one camera covers:

     parent
       ↑
   child ← node → child 

Range = distance 1 in all directions

Where should cameras be placed?

Should we place camera at leaf?
   leaf?????????

Covers:

itself
parent

❌ But does NOT cover siblings or higher nodes well

👉 Not efficient

Better idea: place camera at parent of leaf

    parent
    /   \
 leaf   leaf

One camera covers:

parent
both children

Should we think top-down or bottom-up?

Top-down (wrong)
From root:
You don’t know if children need coverage yet


✅ Bottom-up (correct)
From leaves:

Leaves tell parent: “I am not covered”
Parent decides: “I must place camera”


“Which nodes are NOT covered and force me to act?”


Case 1: Child is NOT covered
👉 Then:

Place camera here

Case 2: Child HAS camera
👉 Then:

I am already covered

Case 3: Children are covered but no camera
👉 Then:
I am NOT covered


    This gives 3 states
    2 → has camera
    1 → covered
    0 → not covered


start from leaf node (POSTORDER TRVAERSAL)


when a node is coverd it will return 1 (no cameera)
when a node is NOT covered it will return 0
when a covered and have camera return 2

leaf node childern means NULL always return 1
    so this force us to not place camera on leaf node 

then leaf node return 0

if(left == 0 || right == 0) return 2; 
    need to place camera here 

if(left == 1 && right == 1) return 0;
    no need to place camera 

if(left == 2 || right == 2) return 1;
    already covered by the parent 









*/
class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root){
        if(!root) return 1; // null is covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // if any child is NOT covered
        if(left == 0 || right == 0){
            cameras++;
            return 2; // has camera
        }

        // if any child has camera
        if(left == 2 || right == 2){
            return 1; // covered
        }

        // else not covered
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0){ // root not covered
            cameras++;
        }
        return cameras;
    }
};
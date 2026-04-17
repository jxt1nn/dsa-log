/** 

    sum of every level than divide it by number of node presnt on that level....

    BFS :
    whene ever extract the nodee from queue add it into sum and count++;

    when level complete 
        sum / count

    and make sum and count again 0

 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        vector<double> ans;

        while(!q.empty()){
            int s = q.size();
            double sum = 0;
            int count = 0; 
            
            for(int i =0;i < s;i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                count++;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double levelAVG = sum / count;
            ans.push_back(levelAVG); 
        }
        return ans;
    }
};
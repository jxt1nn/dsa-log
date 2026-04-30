/**

what a order is best to make tree from string?????????

we go top to bottom 
SO,we can use BFS 

bcoz we hve all levels in order 

how to make string????????

should add null value also in this string

Serialization:

BFS:
get value

string += to_string(node->val) + ","
then push its child 
NO matter they are null or not


deserialization:

we have to travrse this string one by one 
how can we do this ??????

make string into stream

then use gettline function 

and get evry thing before ","

then do simple BFS 

and make tree




 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "null";

        queue<TreeNode*> q;
        q.push(root);

        string str;

        while(!q.empty()){
            int s = q.size();

            for(int i =0; i < s;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    str += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    str += "null,";
                }
            }
        }
        return str;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null") return nullptr;        
        stringstream ss(data);
        string token;
        getline(ss,token,',');

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!getline(ss,token,',')) break; //string remain or not
            
            //left child
            if(token != "null"){
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            if(!getline(ss,token,',')) break;

            // right child 
            if(token != "null"){
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
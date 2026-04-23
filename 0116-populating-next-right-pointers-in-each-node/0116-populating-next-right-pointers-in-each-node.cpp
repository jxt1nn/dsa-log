/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*

given a tree where each node is:

    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;  // 👈 already exists
    }

next pointer already exists
You do NOT create it ❌
You just fill it correctly ✅

For each node:
👉 Connect it to the node on its right (same level)


    how can we do this????????????

    how can we know the next right node of an node

    BFS 
    bcoz bfs give us every level node  in a order 
    left to right

    so we can do one thing 
    
    do bfs:
        we can do one thing
    
    when ever we go to a node connect this node to 
    prev->next 

    we have to carefully maintain the prev node 

    intailly null

    if(prev != null){
        then only do this 

        prev->next = node
    }

    prev = node 


    and after finishing the level 
    prev->next = nuLL


*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = NULL;    

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if(prev != NULL){
                    prev->next = node;
                }
                prev = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
           if(prev) prev->next = NULL;
        }
    return root;
    }
};
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

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            Node *pre=nullptr;
            for(int i=0;i<qsize;i++){
                Node *top=q.front();
                q.pop();
                top->next=pre;
                pre=top;
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }
        return root;
    }
};
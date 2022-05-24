/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node *root,vector<int> &v){
        if(!root) return;
        v.push_back(root->val);
        for(Node *curr:root->children){
            helper(curr,v);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        if(!root) return v;
        helper(root,v);
        return v;
    }
};


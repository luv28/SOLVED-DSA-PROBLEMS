/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int data){
        if(!root) return true;
        if(root->val!=data) return false;
        return helper(root->left,data) && helper(root->right,data);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->val) && helper(root->right,root->val);
    }
};
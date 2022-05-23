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
    void helper(TreeNode* a, TreeNode* b){
        a->val+=b->val;
        if(a->left&&b->left) helper(a->left,b->left);
        if(!a->left) a->left=b->left;
        
        if(a->right&&b->right) helper(a->right,b->right);
        if(!a->right) a->right=b->right;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        helper(root1,root2);
        return root1;
    }
};
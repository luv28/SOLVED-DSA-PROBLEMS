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
    bool helper(TreeNode *root,int t){
        if(root) t=t-root->val;
        if(t==0 && !(root->left || root->right)) return true;
        bool left=false, right=false;
        if(root->left) left=helper(root->left,t);        
        if(root->right) right=helper(root->right,t);
        return right||left;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root,targetSum);
    }
};
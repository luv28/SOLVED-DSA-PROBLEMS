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
    int helper(TreeNode *root,int &l,int &h){
        int ans=0;
        if(!root) return 0;
        if(root->val>=l && root->val<=h) ans+=root->val;
        int left=helper(root->left,l,h);
        int right=helper(root->right,l,h);
        return ans+left+right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root,low,high);
    }
};
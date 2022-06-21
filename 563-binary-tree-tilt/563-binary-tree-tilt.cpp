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
    int helper(TreeNode *root, int &sum){
        if(!root) return 0;
        int ls=helper(root->left,sum);
        int rs=helper(root->right,sum);
        int ts=ls+rs+root->val;
        sum+=abs(ls-rs);
        return ts;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        int a=helper(root,sum);
        return sum;
    }
};
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
    long long ans=LLONG_MAX;
public:
    void helper(TreeNode *root, int minn){
        if(root){
            if(root->val > minn && ans>root->val) ans=root->val;
            else if(minn==root->val){
                helper(root->left,minn);
                helper(root->right,minn);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        helper(root,root->val);
        if(ans==LLONG_MAX) return -1;
        else return ans;
    }
};
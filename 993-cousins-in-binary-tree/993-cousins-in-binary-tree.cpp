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
    void helper(TreeNode *root,int x,int y,pair<int,int> &par,pair<int,int> &level,int currpar,int currlevel){
        if(root->val==x){
            par.first=currpar;
            level.first=currlevel;
        }
        if(root->val==y){
            par.second=currpar;
            level.second=currlevel;
        }
        if(root->left) helper(root->left,x,y,par,level,root->val,currlevel+1);
        if(root->right) helper(root->right,x,y,par,level,root->val,currlevel+1);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> par;
        pair<int,int> level;
        helper(root,x,y,par,level,0,0);
        return par.first!=par.second && level.first==level.second;
    }
};
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
    void helper(TreeNode *root,int t,vector<vector<int>> &ans,vector<int> &temp){
        if(root){
            t=t-root->val;
            temp.push_back(root->val);
        }
        if(t==0 && !(root->left || root->right)){
            ans.push_back(temp);
            return;
        }
        if(root->left){
            helper(root->left,t,ans,temp);
            temp.pop_back();
        }         
        if(root->right){
            helper(root->right,t,ans,temp);
            temp.pop_back();
        }        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root) return ans;
        helper(root,targetSum,ans,temp);
        return ans;
    }
};
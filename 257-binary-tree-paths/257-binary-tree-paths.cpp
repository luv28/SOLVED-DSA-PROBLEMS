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
    void helper(TreeNode *root,vector<string> &ans,string a){
        if(root) a=a+to_string(root->val);
        if(!(root->left || root->right)){
            ans.push_back(a);
            return;
        }
        if(root->left) helper(root->left,ans,a+"->");        
        if(root->right) helper(root->right,ans,a+"->");
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,ans,"");
        return ans; 
    }
};
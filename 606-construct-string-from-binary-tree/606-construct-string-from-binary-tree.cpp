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
    void preorder(TreeNode *root,string &ans){
        if(!root || (root->left==nullptr && root->right==nullptr)) return;
        if(!root->left && root->right){
            ans+='(';
            ans+=')';
        }
        if(root->left){
            ans+='('+to_string(root->left->val);
            preorder(root->left,ans);
            ans.push_back(')');
        }
        if(root->right){
            ans+='('+to_string(root->right->val);
            preorder(root->right,ans);
            ans.push_back(')');
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string ans="";
        if(!(root->left || root->right)){
            ans+=to_string(root->val);
            return ans;
        }
        ans+=to_string(root->val);
        preorder(root,ans);
        return ans;
    }
};
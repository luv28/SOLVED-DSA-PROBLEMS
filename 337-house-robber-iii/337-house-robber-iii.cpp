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
private:
    unordered_map<TreeNode *,int> dp;
public:
    int helper(TreeNode *root){
        if(!root) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
            
        int consider=root->val;
        if(root->left) consider+=helper(root->left->left)+helper(root->left->right);
        if(root->right) consider+=helper(root->right->left)+helper(root->right->right);
        
        int notConsider=0;
        if(root->left) notConsider+=helper(root->left);
        if(root->right) notConsider+=helper(root->right);
        
        return dp[root]=max(consider,notConsider); 
    }
    int rob(TreeNode* root) {
        return helper(root);
    }
};
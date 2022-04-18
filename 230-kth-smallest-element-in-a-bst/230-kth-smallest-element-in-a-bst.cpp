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
    int solve(TreeNode *root,int &k){
        if(root->left){
            int a=solve(root->left,k);
            if(a!=-1) return a;
        }
        k--;
        if(k==0) return root->val;
        if(root->right){
            int a=solve(root->right,k);
            if(a!=-1) return a;
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};
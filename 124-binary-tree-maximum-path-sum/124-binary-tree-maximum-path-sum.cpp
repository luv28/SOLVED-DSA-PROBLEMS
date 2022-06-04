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
    int helper(TreeNode *root,int &maxx){
        int leftMax=0,rightMax=0;
        if(root->left) leftMax=max(helper(root->left,maxx),0);
        if(root->right) rightMax=max(helper(root->right,maxx),0);
        maxx=max(maxx,leftMax+rightMax+root->val);        
        return root->val+max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        if(!(root->left || root->right)) return root->val;
        int maxx=INT_MIN;
        int a=helper(root,maxx);
        return maxx;
    }
};
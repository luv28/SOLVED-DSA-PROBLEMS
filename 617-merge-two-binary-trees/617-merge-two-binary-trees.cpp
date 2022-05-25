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
    TreeNode* helper(TreeNode* r1, TreeNode* r2){
        if(!r1) return r2;
        if(!r2) return r1;
        TreeNode *temp=new TreeNode;
        temp->val=r1->val + r2->val;
        temp->left=helper(r1->left,r2->left);
        temp->right=helper(r1->right,r2->right);
        return temp;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1,root2);
    }
};
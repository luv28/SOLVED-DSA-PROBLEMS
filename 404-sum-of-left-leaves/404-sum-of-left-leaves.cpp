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
    void helper(TreeNode *root,int &sum,int flag){         //flag=1 left leaf    =0 right leaf
        if(!(root->left || root->right) && flag==1){
            sum+=root->val;
        }
        if(root->left) helper(root->left,sum,1);
        if(root->right) helper(root->right,sum,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!(root->left || root->right)) return 0;
        int sum=0;
        helper(root,sum,-1);
        return sum;
    }
};
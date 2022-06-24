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
        if(!root) return 0;
        // if(!(root->left || root->right)) return 0;
        int lh=helper(root->left,maxx);
        int rh=helper(root->right,maxx);
        int dia=lh+rh;
        maxx=max(maxx,dia);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        int height=helper(root,dia);
        return dia;
    }
};
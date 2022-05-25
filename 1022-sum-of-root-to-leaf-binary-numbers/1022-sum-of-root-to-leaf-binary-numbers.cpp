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
    void helper(TreeNode *root,int &sum,int a){
        if(root){
            a=(a*2)+root->val;
        }else return;
        if(!(root->left) && !(root->right)){
          sum+=a; 
            return;
        } 
        helper(root->left,sum,a);        
        helper(root->right,sum,a);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        helper(root,sum,0);
        return sum;
    }
};

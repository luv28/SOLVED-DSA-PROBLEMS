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
    bool isequal(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot) return (!root&&!subRoot);
        else if(root->val==subRoot->val)
            return isequal(root->left,subRoot->left)&&isequal(root->right,subRoot->right);
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if(isequal(root,subRoot)) return true;
        else return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};

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
    void dfs(TreeNode *root,int &sum, TreeNode *parent,TreeNode *grandParent){
        if(grandParent && (grandParent->val)%2==0) sum+=root->val;
        if(root->left) dfs(root->left,sum,root,parent);
        if(root->right) dfs(root->right,sum,root,parent);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        if(!(root->left || root->right)) return sum;
        dfs(root,sum,nullptr,nullptr);
        return sum;
    }
};
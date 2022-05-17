/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode *,TreeNode *>> q;
        q.push({original,cloned});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            TreeNode *ot=a.first;            
            TreeNode *ct=a.second;
            if(ot==target) return ct;
            else {
                if(ot->left)q.push({ot->left,ct->left});                
                if(ot->right)q.push({ot->right,ct->right});
            }
        }
        return nullptr;
    }
};
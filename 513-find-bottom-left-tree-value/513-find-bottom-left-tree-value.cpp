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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans;
        while(!q.empty()){
            int n=q.size();
            int i=n;
            while(i){
                TreeNode * curr=q.front();
                q.pop();
                if(i==n) ans=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                i--;
            }
        }
        return ans;
    }
};
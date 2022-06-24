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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *curr=new TreeNode (val,root,nullptr);
            return curr;
        }
        int currDepth=2;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode * curr=q.front();
                q.pop();
                if(currDepth==depth){
                    if(curr->left){
                        TreeNode *l=curr->left;
                        curr->left=new TreeNode(val,l,nullptr);
                    }else curr->left=new TreeNode(val,nullptr,nullptr);
                    if(curr->right){
                        TreeNode *r=curr->right;
                        curr->right=new TreeNode(val,nullptr,r);
                    }else curr->right=new TreeNode(val,nullptr,nullptr);
                }else{
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            currDepth++;
        }
        return root;
    }
};
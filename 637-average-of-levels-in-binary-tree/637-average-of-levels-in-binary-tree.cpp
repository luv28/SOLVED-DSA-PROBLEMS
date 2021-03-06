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
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            double sum=0,count=0;
            while(n){
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;
                count++;
                if(temp->left) q.push(temp->left);                
                if(temp->right) q.push(temp->right);
                n--;
            }
            ans.push_back(sum/count);
        }
        return ans;
    }
};
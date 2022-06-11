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
    void helper(TreeNode *curr,int k,unordered_set<TreeNode *> &s, vector<int> &ans,unordered_map<TreeNode*, TreeNode *> &m){
        if(!curr || s.find(curr)!=s.end()) return;
        s.insert(curr);
        if(k==0){
            ans.push_back(curr->val);
            return;
        }
        helper(curr->left,k-1,s,ans,m);
        helper(curr->right,k-1,s,ans,m);
        helper(m[curr],k-1,s,ans,m);
    }
    void findParent(TreeNode *curr,unordered_map<TreeNode *,TreeNode *> &m, TreeNode *par){
        if(!curr) return;
        m[curr]=par;
        findParent(curr->left,m,curr);
        findParent(curr->right,m,curr);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root || !target) return ans;
        unordered_map<TreeNode*, TreeNode *> m;
        findParent(root,m,nullptr);
        unordered_set<TreeNode *> s;
        helper(target,k,s,ans,m);
        return ans;
    }
};
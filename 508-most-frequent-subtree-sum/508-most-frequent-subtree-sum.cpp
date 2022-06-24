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
    int helper(TreeNode *root,map<int,int> &m,int &maxCount){
        if(!root) return 0;
        int ls=helper(root->left,m,maxCount);
        int rs=helper(root->right,m,maxCount);
        int sum=root->val+ls+rs;
        m[sum]++;
        maxCount=max(maxCount,m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        vector<int> ans;
        int maxCount=0;
        int sum=helper(root,m,maxCount);
        // for(auto a:m) cout<<a.first<<":"<<a.second<<endl;
        for(auto a:m){
            if(a.second==maxCount) ans.push_back(a.first);
        }
        return ans;
    }
};
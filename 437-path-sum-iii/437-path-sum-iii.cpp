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
    int count=0;
    unordered_map<int,int> m;
    void helper(TreeNode *root,int t, long long sum){
        if(!root) return;
        sum+=root->val;
        int prefixSum=sum-t;
        if(m.find(prefixSum)!=m.end()) count+=m[prefixSum];
        m[sum]++;
        if(root->left) helper(root->left,t,sum);
        if(root->right) helper(root->right,t,sum);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum){
        if(root){
            long long sum=0;
            m[0]=1;
            helper(root,targetSum,sum);
        }
        return count;
    }
};
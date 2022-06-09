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
    void inorder(vector<int> &nums,TreeNode *root){
        if(root->left) inorder(nums,root->left);
        nums.push_back(root->val);
        if(root->right) inorder(nums,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(nums,root);
        int low=0,high=nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==k) return true;
            else if(sum>k) high--;
            else low++;
        }
        return false;
    }
};
class Solution {
    vector<vector<int>> ans;
public:
    void helper(int ci,vector<int>& nums, int n,vector<int> &v){
        if(n==0){
            ans.push_back(v);
            return;
        } 
        if(ci>=nums.size() || n<0) return;
        v.push_back(nums[ci]);
        helper(ci,nums,n-nums[ci],v);
        v.pop_back();
        helper(ci+1,nums,n,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        helper(0,candidates,target,v);
        return ans;
    }
};
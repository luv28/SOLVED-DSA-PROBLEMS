class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans,vector<int> &temp,int ci){
    if(ci==nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[ci]);
    helper(nums,ans,temp,ci+1);
    temp.pop_back();
    helper(nums,ans,temp,ci+1);
    return;
}
vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> temp;
    helper(nums,ans,temp,0);
    return ans;
}
};

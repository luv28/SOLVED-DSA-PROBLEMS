class Solution {
    vector<vector<int>> ans;
public:
    void helper(vector<int> &nums,vector<int> &ve){
        if(nums.size()==0){
            ans.push_back(ve);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            ve.push_back(temp);
            nums.erase(nums.begin()+i);
            helper(nums,ve);
            ve.pop_back();
            nums.insert(nums.begin()+i,temp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ve;
        helper(nums,ve);
        return ans;
    }
};

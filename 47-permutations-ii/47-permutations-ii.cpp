class Solution {
    vector<vector<int>> ans;
    set<vector<int>> s;
public:
    void helper(vector<int> &nums,vector<int> &ve){
        if(nums.size()==0){
            s.insert(ve);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ve;
        helper(nums,ve);
        for(auto a:s) ans.push_back(a);
        return ans;
    }
};
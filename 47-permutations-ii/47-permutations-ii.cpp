class Solution {
    vector<vector<int>> ans;
    unordered_map<int,int> m;
public:
    void helper(vector<int> &nums,vector<int> &ve){
        if(ve.size()==nums.size()){
            ans.push_back(ve);
            return;
        }
        for(auto a:m){
            int num=a.first;
            int count=a.second;
            if(m[num]==0) continue;
            ve.push_back(num);
            m[num]--;
            helper(nums,ve);
            ve.pop_back();
            m[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ve;
        for(auto a:nums) m[a]++;
        helper(nums,ve);
        return ans;
    }
};
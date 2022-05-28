class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=nums.size();
        for(int i=0;i<nums.size();i++) a=(a^nums[i])^i;
        return a;
    }
};
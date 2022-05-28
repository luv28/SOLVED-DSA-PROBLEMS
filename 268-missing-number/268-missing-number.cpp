class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=(nums[0]^0)^nums.size();
        for(int i=1;i<nums.size();i++) a=(a^nums[i])^i;
        return a;
    }
};
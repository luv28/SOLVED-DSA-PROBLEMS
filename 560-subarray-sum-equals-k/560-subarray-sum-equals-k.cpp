class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;       // prefix sum, count
        m[0]=1;
        int sum_i=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum_i+=nums[i];
            if(m.find(sum_i-k)!=m.end()) count+=m[sum_i-k];
            m[sum_i]++;
        }
        return count;
    }
};
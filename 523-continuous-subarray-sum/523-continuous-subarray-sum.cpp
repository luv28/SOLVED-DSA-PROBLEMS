class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        long long int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int remainder=prefixSum%k;
            if(remainder==0 && i>=1) return true;
            if(m.find(remainder)!=m.end()){
                if(m[remainder]<=i-2) return true;
                else continue;
            }
            else m[remainder]=i;
        }
        return false;
    }
};
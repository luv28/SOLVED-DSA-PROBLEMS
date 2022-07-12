class Solution {
public:
    int memo[501];
    int dp(int ci,vector<int> &nums,int &k){
        if(ci==nums.size()) return 0;
        if(memo[ci]!=-1) return memo[ci];
        int ans=INT_MIN,mx=nums[ci];
        for(int i=ci;i<min((int)nums.size(),ci+k);i++){
            mx=max(mx,nums[i]);
            ans=max(ans,(mx*(i-ci+1))+dp(i+1,nums,k));
        }
        return memo[ci]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memo,-1,sizeof(memo));
        return dp(0,arr,k);
    }
};
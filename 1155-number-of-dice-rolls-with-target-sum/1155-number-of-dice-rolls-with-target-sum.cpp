class Solution {
public:
    int helper(int n, int k, int tg,vector<vector<int>> &dp){
        if(n==0 && tg==0) return 1;
        if(tg<=0 || n==0) return 0;
        if(dp[n][tg]!=-1) return dp[n][tg];
        int MOD=1000000007;
        int ans=0;
        for(int i=1;i<=k;i++){
            int ways=helper(n-1,k,tg-i,dp)% MOD;
            ans=ans%MOD;
            ans=(ways+ans)%MOD;
        }
        return dp[n][tg]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        int ans=helper(n,k,target,dp);
        return ans;
    }
};
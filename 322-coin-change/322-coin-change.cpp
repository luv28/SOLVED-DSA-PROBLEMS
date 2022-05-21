class Solution {
public:
    int dp[13][10001];
    int solve(vector<int> &coins,int ci,int amount){
        if(amount==0) return 0;
        if(ci>=coins.size()) return 10001;
        // string s=to_string(ci)+"-"+to_string(amount);
        // if(m.find(s)!=m.end()) return m[s];
        if(dp[ci][amount]!=-1) return dp[ci][amount];
        int take=10001;
        if(amount>=coins[ci]) take=1+solve(coins,ci,amount-coins[ci]);
        int leave=solve(coins,ci+1,amount);
        return dp[ci][amount]=min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        memset(dp,-1,sizeof(dp));
        int a=solve(coins,0,amount);
        if(a>=10001) return -1;
        else return a;
    }
};
class Solution {
    int dp[202][201];
public:
    int helper(vector<vector<int>> &triangle,int ci,int level,int n){
        if(level>n-1) return 0;
        if(dp[ci][level]!=-1) return dp[ci][level];
        int stay=helper(triangle,ci,level+1,n);
        int move=helper(triangle,ci+1,level+1,n);
        return dp[ci][level]=triangle[level][ci]+min(stay,move);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return helper(triangle,0,0,triangle.size());
    }
};
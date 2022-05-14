class Solution {
public:
    int helper(vector<vector<int>>& grid,int r,int c,int n,vector<vector<int>> &dp,int pre){
        if(r>n-1) return 0;
        if(c==pre) return 20001;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans=INT_MAX;
        for(int i=0;i<grid.size();i++){
            int tempans=grid[r][c]+helper(grid,r+1,i,n,dp,c);
            ans=min(ans,tempans);
        }
        return dp[r][c]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid.size()==1) return grid[0][0];
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        int ans=INT_MAX;
        for(int i=0;i<grid.size();i++){
            int tempans=helper(grid,0,i,grid.size(),dp,201);
            ans=min(ans,tempans);
        }
        return ans;
    }
};
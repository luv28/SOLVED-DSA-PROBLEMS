class Solution {
    int dp[201][201];
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int helper(int r,int c,int m,int n, vector<vector<int>>& grid){
        // if(r<0 || r>=m || c<0 || c>=n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans=0;
        for(int i=0;i<dir.size();i++){
            int nr=r+dir[i][0];            
            int nc=c+dir[i][1];
            int temp=0;
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>grid[r][c]) 
                temp=helper(nr,nc,m,n,grid)+1;
            ans=max(ans,temp);
        }
        return dp[r][c]=ans;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==1 && n==1) return 1;
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=1+helper(i,j,m,n,matrix);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
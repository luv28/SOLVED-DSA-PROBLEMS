class Solution {
public:
    int helper(vector<vector<char>>& matrix,int r,int c,int m,int n,vector<vector<int>> &dp){
        if(r>m-1 || c>n-1 || matrix[r][c]=='0') return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int down=1+helper(matrix,r+1,c,m,n,dp);
        int right=1+helper(matrix,r,c+1,m,n,dp);
        int rd=1+helper(matrix,r+1,c+1,m,n,dp);        //right diagonal
        return dp[r][c]=min(rd,min(right,down));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int area=0;
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    int side=helper(matrix,i,j,m,n,dp);
                    area=max(area,side*side);
                }
            }
        }
        return area;
    }
};
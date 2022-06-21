class Solution {
public:
    void dfs(vector<vector<int>> &grid,int row,int col,int n,int m){
        if(row<0 || row>=n || col<0 ||col>=m || grid[row][col]==0) return;
        grid[row][col]=0;
        dfs(grid,row-1,col,n,m);
        dfs(grid,row+1,col,n,m);
        dfs(grid,row,col-1,n,m);
        dfs(grid,row,col+1,n,m);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1||j==m-1) dfs(grid,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) enclaves++;
            }
        }
        return enclaves;
    }
};


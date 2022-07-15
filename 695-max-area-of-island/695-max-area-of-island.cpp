class Solution {
    int maxArea=0;
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int n,int m,int &area){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0) return;
        grid[i][j]=0;
        area++;
        maxArea=max(maxArea,area);
        dfs(grid,i-1,j,n,m,area);
        dfs(grid,i+1,j,n,m,area);
        dfs(grid,i,j-1,n,m,area);
        dfs(grid,i,j+1,n,m,area);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;
                if(grid[i][j]==1) dfs(grid,i,j,n,m,area);
            }
        }
        return maxArea;
    }
};
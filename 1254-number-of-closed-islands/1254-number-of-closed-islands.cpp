class Solution {
public:
    void sink(vector<vector<int>>& grid, int r,int c,int n,int m){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==1) return;
        grid[r][c]=1;
        sink(grid,r-1,c,n,m);
        sink(grid,r+1,c,n,m);        
        sink(grid,r,c-1,n,m);
        sink(grid,r,c+1,n,m);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int j=0;j<m;j++){
            sink(grid,0,j,n,m);
            sink(grid,n-1,j,n,m);
        }
        for(int i=0;i<n;i++){
            sink(grid,i,0,n,m);
            sink(grid,i,m-1,n,m);
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    islands++;
                    sink(grid,i,j,n,m);
                }
            }
        }
        return islands;
    }
};
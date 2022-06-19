class Solution {
public:
    void helper(vector<vector<char>> &grid, int r,int c,int n,int m){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]=='0') return;
        grid[r][c]='0';
        helper(grid,r-1,c,n,m);
        helper(grid,r+1,c,n,m);
        helper(grid,r,c-1,n,m);
        helper(grid,r,c+1,n,m);

    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    helper(grid,i,j,n,m);
                }                
            }
        }
        return islands;
    }
};
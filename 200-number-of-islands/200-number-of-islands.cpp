class Solution {
public:
    
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,+1};
    bool isValid(int r,int c,int n,int m){
        return r>=0 && c>=0 && r<n && c<m;
    }
    void helper(vector<vector<char>> &grid, int r,int c,int n,int m){
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(isValid(nr,nc,n,m)&&grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    grid[nr][nc]='0';
                } 
            }    
        }
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
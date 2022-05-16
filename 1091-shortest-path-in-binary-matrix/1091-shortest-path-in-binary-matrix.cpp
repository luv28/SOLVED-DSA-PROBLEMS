class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==n-1 && c==n-1) return grid[r][c];
            for(int i=0;i<d.size();i++){
                int nr=r+d[i][0];                
                int nc=c+d[i][1];
                if(nr>=0 && nc>=0 && nr<n &&nc<n && grid[nr][nc]==0){
                    q.push({nr,nc});
                    grid[nr][nc]=grid[r][c]+1;
                }
            }
        }
        return -1;
    }
};




    
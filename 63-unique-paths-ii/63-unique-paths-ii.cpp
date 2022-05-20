class Solution {
    int map[101][101];
public:
    int helper(int r,int c,int m,int n,vector<vector<int>>& obstacleGrid){
        if(r==m-1 &&c==n-1) return 1;
        if(r>m-1 || c>n-1 || obstacleGrid[r][c]==1) return 0;
        // string s=to_string(r)+"-"+to_string(c);
        // if(map.find(s)!=map.end()) return map[s];
        if(map[r][c]!=-1) return map[r][c];
        int right=helper(r,c+1,m,n,obstacleGrid);
        int down=helper(r+1,c,m,n,obstacleGrid);
        return map[r][c]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // unordered_map<string,int> map;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        memset(map,-1,sizeof(map));
        return helper(0,0,m,n,obstacleGrid);
    }
};
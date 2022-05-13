class Solution {
public:
    int helper(int r,int c,int m,int n,unordered_map<string,int> &map,vector<vector<int>>& obstacleGrid){
        if(r==m-1 &&c==n-1) return 1;
        if(r>m-1 || c>n-1 || obstacleGrid[r][c]==1) return 0;
        string s=to_string(r)+"-"+to_string(c);
        if(map.find(s)!=map.end()) return map[s];
        int right=helper(r,c+1,m,n,map,obstacleGrid);
        int down=helper(r+1,c,m,n,map,obstacleGrid);
        return map[s]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string,int> map;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        int ans=helper(0,0,m,n,map,obstacleGrid);
        return ans;
    }
};
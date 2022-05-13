class Solution {
public:
    int helper(int r,int c,int m,int n,vector<vector<int>>& grid,unordered_map<string,int> &mp){
        if(r==m-1 && c==n-1) return grid[m-1][n-1];
        if(r>m-1 || c>n-1) return 10001;
        string s=to_string(r)+"-"+to_string(c);
        if(mp.find(s)!=mp.end()) return mp[s];
        int right=grid[r][c]+helper(r,c+1,m,n,grid,mp);
        int down=grid[r][c]+helper(r+1,c,m,n,grid,mp);
        return mp[s]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        unordered_map<string,int> mp;
        int ans=helper(0,0,m,n,grid,mp);
        return ans;
    }
};
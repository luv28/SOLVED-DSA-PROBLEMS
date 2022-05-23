class Solution {
    int dp[601][101][101];   //index,zeroes,ones
public:
    int solve(vector<string>& strs,int ci, int zeros, int ones,unordered_map<int,pair<int,int>> &map){
        if(ci==strs.size()) return 0;
        if(zeros==0 && ones==0) return 0;
        if(dp[ci][zeros][ones]!=-1) return dp[ci][zeros][ones];
        int take=-1;
        if(zeros-map[ci].first>=0 && ones-map[ci].second>=0) 
            take=1+solve(strs,ci+1,zeros-map[ci].first,ones-map[ci].second,map);
        int leave=solve(strs,ci+1,zeros,ones,map);
        return dp[ci][zeros][ones]=max(take,leave);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int,pair<int,int>> map;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<strs.size();j++){
            int a=0;
            int b=0;
            for(int i=0;i<strs[j].length();i++){
                if(strs[j][i]=='0') a++;
                else b++;
            }
            map[j]={a,b};    
        }
        return solve(strs,0,m,n,map);
    }
};
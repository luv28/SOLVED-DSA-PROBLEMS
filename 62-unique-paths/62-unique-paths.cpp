class Solution {
public:
    int helper(int r,int c,int m,int n,unordered_map<string,int> &map){
        if(r==m-1 &&c==n-1) return 1;
        if(r>m-1 || c>n-1) return 0;
        string s=to_string(r)+"-"+to_string(c);
        if(map.find(s)!=map.end()) return map[s];
        int right=helper(r,c+1,m,n,map);
        int down=helper(r+1,c,m,n,map);
        return map[s]=right+down;
    }
    int uniquePaths(int m, int n) {
        unordered_map<string,int> map;
        int ans=helper(0,0,m,n,map);
        return ans;
    }
};
class Solution {
public:
    int helper(vector<vector<int>>& matrix,int r,int c,int n,unordered_map<string,int> &m){
        if(c<0 || c>n-1) return 10001;
        if(r>n-1) return 0;
        string s=to_string(r)+"-"+to_string(c);
        if(m.find(s)!=m.end()) return m[s];
        int ans=INT_MAX;
        for(int i=-1;i<2;i++){
            int tempans=matrix[r][c]+helper(matrix,r+1,c+i,n,m);
            ans=min(ans,tempans);
        }
        return m[s]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        unordered_map<string,int> m;
        for(int i=0;i<matrix.size();i++){
            int tempans=helper(matrix,0,i,matrix.size(),m);
            ans=min(ans,tempans);
        }
        return ans;
    }
};
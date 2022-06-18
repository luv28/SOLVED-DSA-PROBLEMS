class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> s(n+1,false);
        vector<int> ans;
        for(auto a:edges){
            s[a[1]]=true;
        }
        for(int i=0;i<n;i++){
            if(s[i]==false) ans.push_back(i);
        }
        return ans;
    }
};
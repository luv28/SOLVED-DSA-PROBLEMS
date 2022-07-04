class Solution {
public:
    vector<vector<int>> adjL;
    vector<int> ans;
    void dfs(vector<int> &quiet,int cv){
        ans[cv]=cv;
        for(auto neighbour:adjL[cv]){
            if(ans[neighbour]==-1) dfs(quiet,neighbour);
            if(quiet[ans[cv]] > quiet[ans[neighbour]]) ans[cv]=ans[neighbour];
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        adjL.resize(n);
        ans.resize(n,-1);
        for(auto a:richer) adjL[a[1]].push_back(a[0]);
        for(int i=0;i<n;i++){
            if(ans[i]==-1) dfs(quiet,i);
        }
        return ans;
    }
};

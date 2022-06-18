class Solution {
public:
    void dfs(vector<vector<int>>& graph,int curr,int dest, vector<int> &path, vector<vector<int>> &ans,vector<bool> &vis){
        if(curr==dest){
            ans.push_back(path);
            return;
        } 
        for(auto it:graph[curr]){
            if(!vis[it]){
                path.push_back(it);
                dfs(graph,it,dest,path,ans,vis);
                path.pop_back();    
                }
            }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> path;
        vector<bool> vis(n+1,false);
        vector<vector<int>> ans;
        path.push_back(0);
        dfs(graph,0,n-1,path,ans,vis);
        return ans;
    }
};
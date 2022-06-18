class Solution {
    vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>>& graph, vector<bool> &vis,int curr,int dest, vector<int> &path){
        if(curr==dest){
            ans.push_back(path);
            return;
        } 
        for(auto it:graph[curr]){
            if(!vis[it]){
                path.push_back(it);
                dfs(graph,vis,it,dest,path);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n+1,false);
        vector<int> path;
        path.push_back(0);
        dfs(graph,vis,0,n-1,path);
        return ans;
    }
};
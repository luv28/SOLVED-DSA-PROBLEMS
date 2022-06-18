class Solution {
public:
    void dfs(vector<vector<int>>& graph,int curr, vector<int> &path, vector<vector<int>> &ans){
        if(curr==graph.size()-1){
            ans.push_back(path);
            return;
        } 
        for(auto it:graph[curr]){
                path.push_back(it);
                dfs(graph,it,path,ans);
                path.pop_back();    
            }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        path.push_back(0);
        dfs(graph,0,path,ans);
        return ans;
    }
};


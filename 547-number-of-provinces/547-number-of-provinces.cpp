class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int curr,vector<bool> &vis,int n){
        vis[curr]=true;
        for(int i=0;i<n;i++){
            if(isConnected[curr][i]==1 && !vis[i]) dfs(isConnected,i,vis,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=0;
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(isConnected,i,vis,n);
            } 
        }
        return provinces;
    }
};
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(rooms,vis,0);
        for(auto a:vis){
            if(!a) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>> &rooms,vector<bool> &vis,int curr){
        vis[curr]=true;
        for(auto a:rooms[curr]){
            if(!vis[a]) dfs(rooms,vis,a);
        }
    }
};
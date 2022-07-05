class Solution {
public:
    bool bfs(vector<vector<int>> &graph,vector<int> &vis, int cv){
        queue<int> q;
        q.push(cv);
        vis[cv]=0;
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            int currColor=vis[currNode];
            for(auto neighbour:graph[currNode]){
                if(vis[neighbour]==-1){
                    q.push(neighbour);
                    vis[neighbour]=currColor==0?1:0;
                }else if(vis[neighbour]==currColor) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(graph,vis,i)) return false;
            } 
        }
        return true;
        
    }
};
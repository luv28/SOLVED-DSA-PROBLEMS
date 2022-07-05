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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjL(n+1);
        for(auto dislike:dislikes){
            int u=dislike[0];
            int v=dislike[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        vector<int> vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(!bfs(adjL,vis,i)) return false;
            }
        }
        return true;
    }
};

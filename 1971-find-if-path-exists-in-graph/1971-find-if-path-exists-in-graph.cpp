class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjL[n];
        for(auto a:edges){
            adjL[a[0]].push_back(a[1]);
            adjL[a[1]].push_back(a[0]);
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            if(curr==destination) return true;
            for(auto it:adjL[curr]){
                if(vis[it]==0) q.push(it);
            }
        }
        return false;
    }
};


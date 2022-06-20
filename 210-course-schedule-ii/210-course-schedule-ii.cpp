class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adjL(numCourses);
        int visitedCourses=0;
        vector<bool> vis(numCourses,false);
        queue<int> q;
        int n=prerequisites.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            indegree[prerequisites[i][1]]++;
            adjL[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(vis[curr]) continue;
            vis[curr]=true;
            visitedCourses++;
            ans.push_back(curr);
            for(auto a:adjL[curr]){
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        reverse(ans.begin(),ans.end());
        if(visitedCourses==numCourses) return ans;
        else return {};
    }
};
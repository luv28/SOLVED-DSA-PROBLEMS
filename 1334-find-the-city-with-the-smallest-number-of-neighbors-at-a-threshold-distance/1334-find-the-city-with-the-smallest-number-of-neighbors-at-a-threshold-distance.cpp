class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> costs(n,vector<int> (n,INT_MAX));
        int ans=-1,countOfAns=101;
        for(auto a:edges){
            int src=a[0];
            int dest=a[1];
            int cost=a[2];
            costs[src][dest]=cost;
            costs[dest][src]=cost;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        costs[i][j]=0;
                        continue;
                    }
                    if(costs[i][k]!=INT_MAX && costs[k][j]!=INT_MAX)
                        costs[i][j]=min(costs[i][j],costs[i][k]+costs[k][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(costs[i][j]<=distanceThreshold) count++;
            }
            if(countOfAns>=count){
                countOfAns=count;
                ans=i;
            }
        }
        return ans;
    }
};
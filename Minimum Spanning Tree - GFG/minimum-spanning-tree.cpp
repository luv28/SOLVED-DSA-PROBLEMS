// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int find(vector<int> &parents,int a){
        if(parents[a]==a) return a;
        else parents[a]=find(parents,parents[a]);
        return parents[a];
    }
    void unionByRank(vector<int> &parents,vector<int> &rank,int a, int b){
        int rootA=find(parents,a);
        int rootB=find(parents,b);
        if(rank[rootA]>rank[rootB]) parents[rootB]=rootA;
        else if(rank[rootA]<rank[rootB]) parents[rootA]=rootB;
        else {
            parents[rootA]=rootB;
            rank[rootB]++;
        }
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adjL[]){
        int mincost=0;
        vector<int> parents(V);
        for(int i=0;i<V;i++) parents[i]=i;
        vector<int> rank(V,0);
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            int u=i;
            for(auto a: adjL[u]){
                int v=a[0];
                int w=a[1];
                vector<int> edge={w,u,v};
                edges.push_back(edge);    
            }
        }
        sort(edges.begin(),edges.end());
        for(auto edge:edges){
            int w=edge[0];
            int u=edge[1];
            int v=edge[2];
            if(find(parents,u)==find(parents,v)) continue;
            unionByRank(parents,rank,u,v);
            mincost+=w;
        }
        return mincost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
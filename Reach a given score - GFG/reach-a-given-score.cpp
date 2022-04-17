// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int solve(long long int n,long long int table[1002][4],vector<int> score,int ci){
    if(n==0) return 1;
    if(ci>=3) return 0;
    if(table[n][ci]!=-1) return table[n][ci];
    long long int consider=0;
    if(n-score[ci]>=0) consider=solve(n-score[ci],table,score,ci);
    long long int notconsider=solve(n,table,score,ci+1);
    return table[n][ci]=consider+notconsider;
}
long long int count(long long int n)
{
	long long int table[1002][4];
	vector<int> score={3,5,10};
	memset(table, -1, sizeof(table));                 // If 0 sum is required number of ways is 1.
	return solve(n,table,score,0);
}

// long long int ways(int curr,long long int n,vector<int>&score,vector<vector<int>>&vec)
// {
//     if(n==0) return 1;
//     if(curr>=score.size()) return 0;
//     if(vec[curr][n]!=-1) return vec[curr][n];
//     long long int consider = 0;
//     if(score[curr]<=n)
//       consider = ways(curr,n-score[curr],score,vec);
//     long long int notconsider = ways(curr+1,n,score,vec);
//     return vec[curr][n]=consider+notconsider;
// }
// long long int count(long long int n)
// {
// 	vector<int>score{3,5,10};
//     vector<vector<int>>vec(score.size(),vector<int>(1002,-1));
// 	return ways(0,n,score,vec);
// }


// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
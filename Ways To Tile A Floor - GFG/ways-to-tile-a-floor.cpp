// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long dp[100001];
    long long helper(long long ci,long long n){
        if(ci==n) return 1;
        if(ci>n) return 0;
        if(dp[ci]!=-1) return dp[ci];
        return dp[ci]=((helper(ci+1,n)%1000000007)+(helper(ci+2,n)%1000000007))%1000000007;
    }
    long long numberOfWays(long long n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
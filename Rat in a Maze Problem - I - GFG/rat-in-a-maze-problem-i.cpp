// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m, int n,vector<string> &ans, string temp,int r,int c){
        if(r<0||r>=n||c<0||c>=n||m[r][c]<=0) return;
        if(r==n-1 && c==n-1) ans.push_back(temp);
        m[r][c]=-1;
        
        //down
        helper(m,n,ans,temp+"D",r+1,c);
        //up
        helper(m,n,ans,temp+"U",r-1,c);
        //right
        helper(m,n,ans,temp+"R",r,c+1);
        //left
        helper(m,n,ans,temp+"L",r,c-1);
        
        m[r][c]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp="";
        helper(m,n,ans,temp,0,0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
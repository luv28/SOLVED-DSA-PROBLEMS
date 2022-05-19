class Solution {
    int dp[1001][1001];
public:
    int helper(string &s1,string &s2,int i,int j,int n1,int n2){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+helper(s1,s2,i+1,j+1,n1,n2);
        else {
            return dp[i][j]=max(helper(s1,s2,i,j+1,n1,n2),helper(s1,s2,i+1,j,n1,n2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(text1,text2,0,0,text1.length(),text2.length());
    }
};
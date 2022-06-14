class Solution {
    int dp[501][501];
public:
    int helper(string &word1,string &word2,int i,int j,int n1,int n2){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=1+helper(word1,word2,i+1,j+1,n1,n2);
        else return dp[i][j]=max(helper(word1,word2,i+1,j,n1,n2),helper(word1,word2,i,j+1,n1,n2));
        
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n1=word1.length();
        int n2=word2.length();
        int lcsLength=helper(word1,word2,0,0,n1,n2);
        return n1+n2-2*lcsLength;
    }
};
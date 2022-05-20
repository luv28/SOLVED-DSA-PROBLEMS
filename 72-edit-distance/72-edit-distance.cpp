class Solution {
    int m[501][501];
public:
    int helper(string &s1, string &s2,int i,int j,int n1,int n2){
        if(j>=n2) return n1-i;     //n1-i deletions in s1 to make it equal to s2
        if(i>=n1) return n2-j;     //n2-j insertions in s2 to make it equal to s1
        if(m[i][j]!=-1) return m[i][j];
        int ans=100000;
        if(s1[i]==s2[j]) ans=helper(s1,s2,i+1,j+1,n1,n2);
        else {
            int in=1+helper(s1,s2,i,j+1,n1,n2);
            int d=1+helper(s1,s2,i+1,j,n1,n2);            
            int r=1+helper(s1,s2,i+1,j+1,n1,n2);            
            ans=min(in,min(d,r));
        }
        return m[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int i=0,j=0;
        memset(m,-1,sizeof(m));
        return helper(word1,word2,i,j,word1.length(),word2.length());
    }
};
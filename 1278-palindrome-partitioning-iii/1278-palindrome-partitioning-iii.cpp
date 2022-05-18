class Solution {
    int m[101][101];
    // unordered_map<string,int> m;
public:
    int palindrome(string &s,int start,int end){
        int count=0;
        while(start<end){
            if(s[start++]!=s[end--]) count++;
        }
        return count;
    }
    int helper(string &s,int start,int end,int k){
        if(m[start][k]!=-1) return m[start][k]; 
        if(k==1) return m[start][k]=palindrome(s,start,end);
        if(start==end && k>1) return m[start][k]=1001;
        int ans=1001;
        for(int i=start;i<end;i++){
            int count=0;
            count+=palindrome(s,start,i);
            count+=helper(s,i+1,end,k-1);
            ans=min(ans,count);
        }
        return m[start][k]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.length();
        if(n==k) return 0;
        if(k==1) return palindrome(s,0,n-1);
        memset(m,-1,sizeof(m));
        int ans=1001;
        for(int i=0;i<n-1;i++){
            int count=0;
            count+=palindrome(s,0,i);
            count+=helper(s,i+1,n-1,k-1);
            ans=min(ans,count);
        }
        return ans;
    }
};
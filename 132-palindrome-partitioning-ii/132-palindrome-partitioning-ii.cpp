class Solution {
public:
    bool palindrome(string &s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    int helper(string &s,int start,int end,vector<int> &m){
        if(palindrome(s,start,end)) return m[start]=0;               
        if(m[start]!=-1) return m[start];
        int ans=20001;
        for(int i=start;i<end;i++){
            if(palindrome(s,start,i)){
                int c=1+helper(s,i+1,end,m);
                ans=min(ans,c);    
            }
        }
        return m[start]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        if(n==1) return 0;
        vector<int> m(2001,-1);
        return helper(s,0,n-1,m);
    }
};
    
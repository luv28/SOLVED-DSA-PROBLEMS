class Solution {
    int m[2001][4];
public:
    bool ispalindrome(string &s,int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    bool helper(string &s,int start,int end,int k){//vector<vector<int>> &m){
        if(m[start][k]!=-1) return m[start][k];
        // string str=to_string(start)+"-"+to_string(k);
        // if(m.find(s)!=m.end()) return m[s];
        if(start==end && k>1) return m[start][k]=false;
        if(k==1){
            if(ispalindrome(s,start,end)) return m[start][k]=true;
            else return m[start][k]=false;
        }
        bool ans=false;
        for(int i=start;i<end;i++){
            if(ispalindrome(s,start,i)){
                bool tempans= helper(s,i+1,end,k-1);
                if(tempans) return m[start][k]=true;
                ans=ans || tempans;
            }
        }
        return m[start][k]=ans;
    }
    bool checkPartitioning(string s) {
        if(s.length()==3) return true;
        // vector<vector<int>> m(2001,vector<int>(4,-1));
        // unordered_map<string,int> m;
        memset(m,-1,sizeof(m));
        return helper(s,0,s.length()-1,3);
    }
};
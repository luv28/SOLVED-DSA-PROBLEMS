class Solution {
    vector<vector<string>> ans;
public:
    bool ispalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void helper(string &s,int start,vector<string> &ways,int n){
        if(start==n){
            ans.push_back(ways);
            return;
        }
        for(int i=start;i<n;i++){
            if(ispalindrome(s,start,i)){
                ways.push_back(s.substr(start,i-start+1));
                helper(s,i+1,ways,n);
                ways.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        vector<string> ways;
        int n=s.size();
        helper(s,0,ways,n);
        return ans;
    }
};
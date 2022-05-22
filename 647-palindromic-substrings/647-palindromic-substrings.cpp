class Solution {
public:
    bool ispalindrome(string &s,int st,int e){
        while(st<e){
            if(s[st++]!=s[e--]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(ispalindrome(s,i,j)) count++;
            }
        }
        return count;
    }
};
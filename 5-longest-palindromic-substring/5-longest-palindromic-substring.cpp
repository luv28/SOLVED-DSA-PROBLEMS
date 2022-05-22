class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false; 
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxx=0;
        pair<int,int> p;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    if(maxx<j-i+1){
                        maxx=j-i+1;
                        p={i,j};
                    }
                }
            }
        }
        return s.substr(p.first,p.second-p.first+1);;
    }
};
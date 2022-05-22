class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false; 
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxx=0;
        pair<int,int> p;
        for(int i=1,l=0,r=2;i<n;i++,l=i-1,r=i+1){
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxx<r-l+1){
                    maxx=r-l+1;
                    p={l,r};
                }
                l--;
                r++;
            }
        }
        for(int i=0,l=0,r=1;i<n-1;i++,l=i,r=i+1){
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxx<r-l+1){
                    maxx=r-l+1;
                    p={l,r};
                }
                l--;
                r++;
            }
        }
        return s.substr(p.first,p.second-p.first+1);
    }
};


class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> m;
        if(s.length()<3) return 0;
        int i=0,count=0,j=0,n=s.length();
        while(j<n){
            m[s[j]]++;
            if(j-i+1==3){
                if(m.size()==3) count++;
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return count;
    }
};
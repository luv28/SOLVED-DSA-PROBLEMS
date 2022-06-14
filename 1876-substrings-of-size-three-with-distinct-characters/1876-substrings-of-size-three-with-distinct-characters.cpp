class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> m;
        if(s.length()<3) return 0;
        int i=0,count=0,j=0,n=s.length();
        while(j<3){
            m[s[j++]]++;
        }
        if(m.size()==3) count++;
        for(int i=3;i<n;i++){
            m[s[i]]++;
            m[s[i-3]]--;
            if(m[s[i-3]]==0) m.erase(s[i-3]);
            if(m.size()==3) count++;

        }
        return count;
    }
};
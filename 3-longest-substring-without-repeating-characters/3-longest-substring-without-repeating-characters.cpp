class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int start=0,res=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end() && m[s[i]]>=start) start=m[s[i]]+1;
            m[s[i]]=i;
            res=max(res,i-start+1);
            }
        
        return res;
    }
};

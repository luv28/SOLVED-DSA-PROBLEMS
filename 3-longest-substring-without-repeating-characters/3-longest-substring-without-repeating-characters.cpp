class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int start=0,end=0,res=0;
        while(end<s.length()){
            if(m.find(s[end])!=m.end()){
                m.erase(s[start]);
                start++;
            }else{
                m[s[end]]=end;
                res=max(res,end-start+1);
                end++;
            }
        }
        return res;
    }
};

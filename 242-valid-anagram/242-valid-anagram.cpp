class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> l;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            l[s[i]]++;
            m[t[i]]++;
        }
        if(l!=m) return false;
        return true;
    }
};
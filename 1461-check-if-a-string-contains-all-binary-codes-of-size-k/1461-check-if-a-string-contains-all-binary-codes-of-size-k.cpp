class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        if(n<k) return false;
        unordered_set<string> set;
        for(int i=0;i<=n-k;i++) set.insert(s.substr(i,k));
        return set.size()==1<<k;
    }
};
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char a:s) freq[a-'a']++;
        int ans=0;
        unordered_set<int> seen;
        for(int i=0;i<26;i++){
            while(freq[i] && seen.find(freq[i])!=seen.end()){
                freq[i]--;
                ans++;
            }
            seen.insert(freq[i]);
        }
        return ans;
    }
};
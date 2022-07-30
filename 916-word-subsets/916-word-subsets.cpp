class Solution {
public:
    vector<int> findFreq(string &word){
        vector<int> freq(26,0);
        for(auto letter:word) freq[letter-'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26,0);
        vector<string> ans;
        for(auto word:words2){
            vector<int> freq=findFreq(word);
            for(int i=0;i<26;i++) maxFreq[i]=max(maxFreq[i],freq[i]);
        }
        for(auto word:words1){
            vector<int> freq=findFreq(word);
            for(int i=0;i<26;i++){
                if(freq[i]<maxFreq[i]) break;
                if(i==25) ans.push_back(word);
            }
        }
        return ans;
    }
};
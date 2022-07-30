class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        string ans="";
        int minn=INT_MAX;
        bool flag=true;
        for(auto word:words) minn=min(minn,(int)word.length());
        for(int i=0;i<minn;i++){
            char c=words[0][i];
            for(auto word:words){
                if(word[i]!=c) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
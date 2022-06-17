class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> in;
        unordered_map<int,int> out;
        for(auto a:trust){
            in[a[1]]++;
            out[a[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==n-1 && out[i]==0) return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        vector<int> ans;
        for(auto a:edges){
            s.insert(a[1]);
        }
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(char c:s){
            if(stk.empty()||stk.back().first!=c) stk.push_back({c,1});
            else{
                stk.back().second++;
                if(stk.back().second==k) stk.pop_back();
            }
        }
        string res="";
        for(auto a : stk) {
            res.append(a.second,a.first);
        }
        return res;
        
    }
};
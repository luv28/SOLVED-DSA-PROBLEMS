class Solution {
    vector<vector<int>> v;
public:
    void helper(int k,int n,int num,vector<int> &ve){
        if(k==0){
            if(n==0) v.push_back(ve);
            return;
        }
        if(num>9) return;
        ve.push_back(num);
        helper(k-1,n-num,num+1,ve);
        ve.pop_back();
        helper(k,n,num+1,ve);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ve;
        helper(k,n,1,ve);
        return v;
    }
};
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        vector<int> ans;
        for(auto a:rolls) sum+=a;
        int reqSum=(mean*(rolls.size()+n))-sum;
        if(reqSum>(6*n) || reqSum<0 || reqSum<n) return ans;
        int rem=reqSum%n;
        for(int i=0;i<n;i++) ans.push_back(reqSum/n);
        for(int i=0;i<n;i++){
            if(rem!=0){
                ans[i]+=1;
                rem--;
            }else break;
        }
        return ans;
    }
};
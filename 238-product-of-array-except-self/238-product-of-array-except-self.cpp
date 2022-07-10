class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        // vector<int> prefix(n+1,1);
        // vector<int> suffix(n+1,1);
        vector<int> ans(n,1);
        // for(int i=0;i<n;i++) prefix[i+1]=prefix[i]*nums[i];
        for(int i=n-2;i>=0;i--) ans[i]=ans[i+1]*nums[i+1];
        // for(int i=0;i<n;i++) ans[i]=prefix[i]*suffix[i+1];
        int leftProduct=1;
        for(int i=0;i<n;i++){
            ans[i]=ans[i]*leftProduct;
            leftProduct*=nums[i];
        }
        return ans;
    }
};
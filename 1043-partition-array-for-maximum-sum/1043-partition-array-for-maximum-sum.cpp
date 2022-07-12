class Solution {
public:
    // int ans=INT_MIN;
    int dp[501][501];
    int helper(vector<int> &nums,int &k,int ci,int count,int maxi){
        int &ans=dp[ci][count];
        // if(ci==nums.size()-1){
        //     sum+=count*maxi;
        //     // ans=max(ans,sum);
        //     return ans=sum;
        // }
        if(ans!=-1) return ans;
        //change track
        int change=(maxi*count);
        if(ci+1!=nums.size()) change += helper(nums,k,ci+1,1,nums[ci+1]);
        //dont change track
        int changeNot=INT_MIN;
        if(count+1<=k && ci+1!=nums.size()) changeNot = helper(nums,k,ci+1,count+1,max(maxi,nums[ci+1]));
        return ans=max(change,changeNot);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        return helper(arr,k,0,1,arr[0]);
    }
};
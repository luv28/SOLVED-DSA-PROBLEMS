class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int low=0,high=0,n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        while(high<n){
            sum+=nums[high];
            if(sum<target) high++;
            else{
                while(sum>=target){
                    ans=min(ans,high-low+1);
                    sum-=nums[low];
                    low++;
                }
                high++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
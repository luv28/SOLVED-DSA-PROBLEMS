class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start=0;
        int currSum=0;
        int maxSum=INT_MIN;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]++;
                currSum+=nums[i];
                maxSum=max(maxSum,currSum);
            }else{
                m[nums[i]]++;
                currSum+=nums[i];
                while(m[nums[i]]!=1){
                    currSum-=nums[start];
                    m[nums[start]]--;
                    if(m[nums[start]]==0) m.erase(nums[start]);
                    start++;
                }
            }
        }
        return maxSum;
    }
};
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        long long int sum=0,st=nums[0][0];
        for(int i=0;i<nums.size();i++){
            if(st>=nums[i][0]){
                sum+=nums[i][1]+st-nums[i][0];
            } 
            else{
                st=nums[i][0];
                sum+=nums[i][1]+st-nums[i][0];
            }
            st+=nums[i][1];
        }
        return (double)sum/(double)nums.size();
    }
};
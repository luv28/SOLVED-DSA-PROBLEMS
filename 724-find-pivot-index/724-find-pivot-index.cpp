class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        // vector<int> sumRL(n,0);
        // for(int i=n-2;i>=0;i--) sumRL[i]=sumRL[i+1]+nums[i+1];
        int sumLR=0,sumRL=0;
        for(int i=1;i<n;i++) sumRL+=nums[i];
        for(int i=0;i<n;i++){
            if(sumLR==sumRL) return i;
            sumLR+=nums[i];
            if(i+1<n)sumRL-=nums[i+1];
        }
        return -1;
    }
};
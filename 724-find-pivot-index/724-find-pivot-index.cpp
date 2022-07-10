class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> sumRL(n,0);
        for(int i=n-2;i>=0;i--) sumRL[i]=sumRL[i+1]+nums[i+1];
        int sumLR=0;
        for(int i=0;i<n;i++){
            if(sumLR==sumRL[i]) return i;
            sumLR+=nums[i];
        }
        return -1;
    }
};
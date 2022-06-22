class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int pi=0,ls=0,rs=0;
        for(int i=1;i<n;i++){
            rs+=nums[i];
        }
        while(ls!=rs && pi<n){
            ls+=nums[pi];
            pi++;
            if(pi==n) rs=0;
            else rs-=nums[pi];
        }
        if(pi==n) return -1;
        else return pi;
    }
};
class Solution {
public:
    int firstOccurence(vector<int> &nums, int &target){
        int low=0,high=nums.size()-1,mid=0;
        int result=-1;
        while(low<=high){
            mid=(high-low)/2 +low;
            if(nums[mid]==target){
                result=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return result;
    }
    int lastOccurence(vector<int> &nums, int &target){
        int low=0,high=nums.size()-1,mid=0;
        int result=-1;
        while(low<=high){
            mid=(high-low)/2 +low;
            if(nums[mid]==target){
                result=mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int first=firstOccurence(nums,target);
        int last=lastOccurence(nums,target);
        return {first,last};
    }
};

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		int sum=0;
        for(auto a:nums) sum+=a;
        if(sum < x) return -1;
		if(sum == x) return nums.size();
		int target= sum-x, currSum=0, start=0, maxSize = 0;
		for(int i=0;i<nums.size();i++){
			currSum += nums[i];
			while(currSum>target)
				currSum -= nums[start++];
			if(currSum == target)
				maxSize = max(maxSize, i - start + 1);
		}
		return (maxSize == 0) ? - 1 : nums.size() - maxSize;
	}
};
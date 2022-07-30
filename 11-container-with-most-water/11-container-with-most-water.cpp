class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,n=height.size(),high=n-1;
        int ans=0;
        while(low<high){
            int a=height[low];
            int b=height[high];
            int area=min(a,b)*(high-low);
            ans=max(ans,area);
            if(a<b){
                while(low<high){
                    if(height[low]>a) break;
                    else low++;
                }
            }
            else{
                while(low<high){
                    if(height[high]>b) break;
                    else high--;
                }
            }
        }
        return ans;
    }
};
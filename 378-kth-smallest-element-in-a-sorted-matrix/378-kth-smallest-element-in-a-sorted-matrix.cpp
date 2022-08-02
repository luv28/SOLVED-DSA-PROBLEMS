class Solution {
public:
    int kthSmallest(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols=grid[0].size();
        int low=grid[0][0],high=grid[rows-1][cols-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int j=cols-1;
            int count=0;
            for(int i=0;i<rows;i++){
                while(j>=0 && grid[i][j]>mid) j--;
                count+=j+1;
            }
            if(count<k) low=mid+1;
            else high=mid;
        }
        return low;
    }
};
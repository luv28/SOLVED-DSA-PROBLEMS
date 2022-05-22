class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int r=0,c=cols-1;
        while(r<rows && r>=0 && c<cols && c>=0){
            int a=matrix[r][c];
            if(target==a) return true;
            else if(target<a) c--;
            else r++;
        }
        return false;
    }
};
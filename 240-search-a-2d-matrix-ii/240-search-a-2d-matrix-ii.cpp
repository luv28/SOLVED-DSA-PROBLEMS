class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int r=0,c=cols-1;
        while(r>=0 && r<rows && c>=0 && c<cols){
            int a=matrix[r][c];
            if(a==target) return true;
            else if(a>target) c--;
            else r++;
        }
        return false;
    }
};
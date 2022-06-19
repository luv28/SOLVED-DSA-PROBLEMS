class Solution {
public:
    void helper(vector<vector<int>> &image,int r,int c,int val,int n,int m,int color){
        if(r>=0 && r<n && c>=0 && c<m && image[r][c]!=color && image[r][c]==val){
            image[r][c]=color;
            helper(image,r-1,c,val,n,m,color);
            helper(image,r+1,c,val,n,m,color);
            helper(image,r,c-1,val,n,m,color);
            helper(image,r,c+1,val,n,m,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int val=image[sr][sc];
        helper(image,sr,sc,val,image.size(),image[0].size(),color);
        return image;
    }
};
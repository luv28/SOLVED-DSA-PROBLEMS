class Solution {
    public:    
    bool isValid(int n,vector<string> &board, int currRow,int currCol){
        for(int row=currRow;row>=0;row--){
            if(board[row][currCol]=='Q') return false;
        }
        
        for(int row=currRow,col=currCol ; row>=0 && col>=0 ; row--,col--){
            if(board[row][col]=='Q') return false;
        }
        
        for(int row=currRow,col=currCol ; row>=0 && col<n ; row--,col++){
            if(board[row][col]=='Q') return false;
        }
        return true;
    }
    void helper(int n, vector<string> &board, int row,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(n,board,row,col)){
                board[row][col]='Q';
                helper(n,board,row+1,ans);
                board[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        helper(n,board,0,ans);
        return ans;
    }
};
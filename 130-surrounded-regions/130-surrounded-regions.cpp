class Solution {
public:
    void dfs(vector<vector<char>> &board,int row,int col){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!='O') return;
        board[row][col]='R';
        dfs(board,row-1,col);
        dfs(board,row+1,col);
        dfs(board,row,col-1);
        dfs(board,row,col+1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(board,0,j);
            dfs(board,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='R') board[i][j]='O'; 
            }
        }
    }
};
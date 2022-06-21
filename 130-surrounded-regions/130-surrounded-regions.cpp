class Solution {
public:
    void dfs(vector<vector<char>> &board,int row,int col,char change){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!='O') return;
        board[row][col]=change;
        dfs(board,row-1,col,change);
        dfs(board,row+1,col,change);
        dfs(board,row,col-1,change);
        dfs(board,row,col+1,change);
        return;
    }
    void dfsAgain(vector<vector<char>> &board,int row,int col,char detect,char change){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!=detect) return;
        board[row][col]=change;
        dfsAgain(board,row-1,col,detect,change);
        dfsAgain(board,row+1,col,detect,change);
        dfsAgain(board,row,col-1,detect,change);
        dfsAgain(board,row,col+1,detect,change);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O') dfs(board,i,j,'Z');
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(board[i][j]=='O') dfs(board,i,j,'X');
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='Z') dfsAgain(board,i,j,'Z','O');
            }
        }
    }
};
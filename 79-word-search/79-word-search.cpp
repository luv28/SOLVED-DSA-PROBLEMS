class Solution {
public:
    bool dfs(vector<vector<char>>& board,int &n,int &m,int r,int c, string &word,int ci){
        if(ci>=word.size()) return true;
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]!=word[ci]) return false;
        char temp=board[r][c];
        board[r][c]='!';
        bool found=dfs(board,n,m,r-1,c,word,ci+1);
        found=found||dfs(board,n,m,r+1,c,word,ci+1);
        found=found||dfs(board,n,m,r,c-1,word,ci+1);
        found=found||dfs(board,n,m,r,c+1,word,ci+1);
        board[r][c]=temp;
        if(found) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,n,m,i,j,word,0)) return true;
                }
            }
        }
        return false;
    }
};
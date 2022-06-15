class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0,9);
        return;
    }
    bool sudokuSolver(vector<vector<char>>& board,int currentRow,int currentCol,int n){
        if(currentRow==n) return true;
        int nextRow=-1;
        int nextCol=-1;
        if(currentCol!=n-1){
            nextRow=currentRow;
            nextCol=currentCol+1;
        }else{
            nextRow=currentRow+1;
            nextCol=0;
        }
        if(board[currentRow][currentCol]!='.')
            return sudokuSolver(board,nextRow,nextCol,n);
        for(int i=1;i<=9;i++){
            if(isValid(board,currentRow,currentCol,i,n)){
                board[currentRow][currentCol]=i+'0';
                bool nextCell=sudokuSolver(board,nextRow,nextCol,n);
                if(nextCell) return true;
                board[currentRow][currentCol]='.';
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board,int currentRow,int currentCol,int currentVal,int n){
        return isRowValid(board,currentRow,currentCol,currentVal,n)&&isColValid(board,currentRow,currentCol,currentVal,n)&&isSubGridValid(board,currentRow,currentCol,currentVal,n);
    }
    bool isRowValid(vector<vector<char>> &board,int currentRow,int currentCol,int currentVal,int n){
        for(int i=0;i<n;i++){
            if(board[currentRow][i]==currentVal+'0') return false;
        }
        return true;
    }
    bool isColValid(vector<vector<char>> &board,int currentRow,int currentCol,int currentVal,int n){
        for(int i=0;i<n;i++){
            if(board[i][currentCol]==currentVal+'0') return false;
        }
        return true;
    }
    bool isSubGridValid(vector<vector<char>> &board,int currentRow,int currentCol,int currentVal,int n){
        int rowStart=3*(currentRow/3);
        int colStart=3*(currentCol/3);
        for(int i=rowStart;i<rowStart+3;i++){
            for(int j=colStart;j<colStart+3;j++){
                if(board[i][j]==currentVal+'0') return false;
            }
        }
        return true;
    }
};
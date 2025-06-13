class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n,false),diag1(2*n-1,false),diag2(2*n-1,false); // 水平 左斜 右斜
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtracking(0,n,board,cols,diag1,diag2,res);
        return res;
    }

    void backtracking(int row, int n, vector<string>& board,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int col = 0; col<n; ++col) {
            if(cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[row+col] = diag2[row-col+n-1]=true;
            backtracking(row+1,n,board,cols,diag1,diag2,res);
            board[row][col] = '.';
            cols[col] = diag1[row+col] = diag2[row-col+n-1]=false;
        }    
    
    }
};
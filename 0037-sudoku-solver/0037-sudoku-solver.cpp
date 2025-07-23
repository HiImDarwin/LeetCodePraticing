class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> block(9);
      vector<unordered_set<char>> col(9); 
      vector<unordered_set<char>> row(9);  
      for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
          if(board[i][j] == '.') continue;
          block[(i/3)*3 + j/3].insert(board[i][j]);
          row[i].insert(board[i][j]);
          col[j].insert(board[i][j]);
        }
      }
      dfs(0,0,board,block,col,row);
    }
    bool dfs(int x, int y , vector<vector<char>>& board, vector<unordered_set<char>> &block, vector<unordered_set<char>> &col,  vector<unordered_set<char>> &row) {
      if(x == 9) return true;
      if(y == 9) return dfs(x+1, 0, board, block, col, row);
      if(board[x][y]!= '.') return dfs(x, y+1, board, block, col, row);
      for (char c = '1'; c <= '9'; ++c) {
        if(!isValid(x, y, c, block,col,row)) continue;
        board[x][y] = c;
        block[(x/3)*3 + y/3].insert(c);
        row[x].insert(c);
        col[y].insert(c);
        if(dfs(x, y+1, board, block, col, row)) return true;
        board[x][y] = '.'; 
        block[(x/3)*3 + y/3].erase(c);
        row[x].erase(c);
        col[y].erase(c);
      }
      return false;
    }
    bool isValid(int x, int y , char c, vector<unordered_set<char>> &block, vector<unordered_set<char>> &col,  vector<unordered_set<char>> &row) {
      int b = (x/3)*3 + y/3;
      if (block[b].count(c) || row[x].count(c) || col[y].count(c)) return false;
      return true;
    }
};
class Solution {
  vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y) {
    if (idx == word.length()) {
      return true;
    } else if(x < 0 || y < 0 || x >= board.size() || 
          y >= board[0].size() || word[idx] != board[x][y]) {
        return false; 
    } 
    board[x][y] = '#';
    bool res = false;
    for (const auto& [dx, dy] : dir) {
      int nei_x = x + dx;
      int nei_y = y + dy;
      if (dfs(board, word, idx + 1, nei_x, nei_y)) {
        return true;
      }
    }
    board[x][y] = word[idx];
    return false;
  }
};

// DFS
// DFS + 狀態壓縮
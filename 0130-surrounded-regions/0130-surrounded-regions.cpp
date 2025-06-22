class Solution {
  public:
    void solve(vector<vector<char>>& board) {
      int m = board.size();
      int n = board[0].size();
      if(m <=2 || n <= 2) return;
      vector<vector<bool>> visited(m, vector<bool>(n,false));
      vector<pair<int,int>> changeRegion;
      for (int i = 1; i < m-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if(board[i][j] == 'O' && !visited[i][j] && 
               !findSurrounded(board, visited, i, j)) {
                changeRegion.push_back({i, j});
            }
        }
      }

      for(auto [x,y] : changeRegion) {
        replace(board, x, y);
      }
        
    }

  private:
    bool findSurrounded(vector<vector<char>>& board, vector<vector<bool>> &visited, int xIdx, int yIdx){
      int m = board.size();
      int n = board[0].size();
      bool touchBoarder = false;
      queue<pair<int,int>> qu;
      qu.push({xIdx, yIdx});
      while(!qu.empty()) {
        auto [x,y] = qu.front(); qu.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (auto [dx, dy] : directions) {
          int newX = x + dx, newY = y + dy;
          if((newX == 0 || newX == m-1 || newY == 0 || newY == n-1) &&
            board[newX][newY] == 'O'){
            touchBoarder = true;
          } else if ( 0 < newX && newX < m - 1 && 0 < newY && newY < n - 1) {
            if( board[newX][newY] == 'O' && !visited[newX][newY]) {
                qu.push({newX, newY});
            }
          }
        }
      }
      return touchBoarder;
   }

    void replace(vector<vector<char>>& board, int xIdx, int yIdx){
      int m = board.size();
      int n = board[0].size();
      if(xIdx < 0 || xIdx == m || yIdx < 0 || yIdx == n || board[xIdx][yIdx] == 'X') {
        return;
      }
      board[xIdx][yIdx] = 'X';
      for(auto [dx, dy] : directions) {
        replace(board, xIdx + dx, yIdx + dy);
      }
    } 

    const vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
};
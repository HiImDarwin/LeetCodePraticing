class Solution 
{
  public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
      queue<pair<int,int>> positionQu;
      positionQu.push({click[0],click[1]});
      while(!positionQu.empty()) {
        auto [x, y] = positionQu.front();
        positionQu.pop();
        if (isRevealed(board[x][y])) {
          continue;
        }
        if (board[x][y] == 'M') {
          board[x][y] = 'X';
          return board;
        }
        int adjBomb = checkAround(board, x, y);
        if (adjBomb == 0) {
          board[x][y] = 'B';
          for(auto [dx, dy] : directions) {
            int adjX = x + dx;
            int adjY = y + dy;
            if(adjX < 0 || adjX >= board.size() || adjY < 0 || adjY >= board[0].size()) {
              continue;
            }
            positionQu.push({adjX,adjY});
          }
        } else {
          board[x][y] = ('0' + adjBomb);
        }
      }
      
      return board;
    }

    bool isRevealed (char c) 
    {
      if(c == 'B' || c <='8' && c >= '1') return true;
      return false;
    }

    int checkAround (vector<vector<char>>& board, int x, int y) 
    {
      int bombCount = 0;
      for(auto [dx, dy] : directions) {
        int adjX = x + dx;
        int adjY = y + dy;
        if(adjX < 0 || adjX >= board.size() || adjY < 0 || adjY >= board[0].size()) {
          continue;
        }
        if (board[adjX][adjY] == 'M') {
          bombCount++;
        }
      }
      return bombCount;
    }

    vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};
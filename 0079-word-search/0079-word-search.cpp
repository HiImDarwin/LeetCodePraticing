class Solution {
  public:
    bool exist(vector<vector<char>>& board, string word) {
      for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[0].size(); ++j) {
          if(board[i][j] == word[0] && DFS(board, word, i, j, 0)) 
            return true;
        }
      }
      return false;
    }
  private:
    bool DFS(vector<vector<char>>& board, string& word, int xIdx, int yIdx, int index) {
      if(xIdx <0 || xIdx == board.size() || yIdx < 0 || yIdx == board[0].size()) return false;
      if(board[xIdx][yIdx] == word[index]) {
        if (index == word.size()-1) return true;
      } else {
        return false;
      }
      char c = board[xIdx][yIdx] ;
      board[xIdx][yIdx] = '#';

      bool result = false;
      result = DFS(board,word,xIdx+1,yIdx,index+1) ||
               DFS(board,word,xIdx-1,yIdx,index+1) ||
               DFS(board,word,xIdx,yIdx+1,index+1) ||
               DFS(board,word,xIdx,yIdx-1,index+1);
      board[xIdx][yIdx] = c;
      return result;
    }
};
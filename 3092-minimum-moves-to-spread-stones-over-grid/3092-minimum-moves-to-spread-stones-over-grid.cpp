class Solution {
  int minMove = INT_MAX;
public:
    int minimumMoves(vector<vector<int>>& grid) {
      DFS(0, 0, grid);
      return minMove;
    }
    void DFS(int cur, int moves, vector<vector<int>> &grid) {
      if(moves >= minMove) return;
      if(cur == 9) {
        minMove = min(minMove, moves);
        return;
      }
      int i = cur/3;
      int j = cur%3;
      if(grid[i][j] != 0) {
        DFS(cur+1, moves, grid);
        return;
      }
      for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
          if(grid[x][y] <=1) continue;
          grid[x][y]-=1;
          grid[i][j]+=1;
          DFS(cur+1,moves+abs(x-i) +abs(y-j),grid);
          grid[x][y]+=1;
          grid[i][j]-=1;
        }
      }
    }
};


/*
do the bfs from each 0  find the nearest 2


*/
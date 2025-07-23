class Solution {
  int m;
  int n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int res = INT_MIN;
      m = matrix.size();
      n = matrix[0].size();
      unordered_map<int,int> memo;
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          res = max(res, dfs(i*n+j,matrix,memo));
        }
      }
      return res;
    }
    int dfs(int index, vector<vector<int>>& matrix, unordered_map<int,int> &memo) {
      if(memo.find(index) != memo.end()) {
        return memo[index];
      }
      int x = index/n; 
      int y = index%n;
      int maxPath = 1;
      for(auto [dx, dy] : direction) {
        int neiX = x + dx;
        int neiY = y + dy;
        int path=0;
        if(neiX < m && neiX >=0 && neiY < n && neiY >=0 && matrix[neiX][neiY] > matrix[x][y]) {
          path = dfs(neiX*n+neiY , matrix, memo);
        }
        maxPath = max(maxPath, 1+path);
      }
      memo[index] = maxPath;
      return maxPath;
    }
    const vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
};
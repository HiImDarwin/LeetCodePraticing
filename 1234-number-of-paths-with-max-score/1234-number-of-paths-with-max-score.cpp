class Solution {
  const int MOD = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
      int m = board.size();
      int n = board[0].size();
      vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n,{0,0}));
      dp[m-1][n-1] = {0,1};
      for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {

          if (board[i][j] == 'X' || (i == m-1 && j == n-1)) continue;
          int val = (board[i][j] == 'E' || board[i][j] == 'S') ? 0 : board[i][j] - '0';
          for (auto [dx, dy] : directions) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni >= m || nj >= n) continue;
            if (dp[ni][nj].second == 0) continue;

            int totalScore = dp[ni][nj].first + val;

            if (totalScore > dp[i][j].first) {
              dp[i][j].first = totalScore;
              dp[i][j].second = dp[ni][nj].second;
            } else if (totalScore == dp[i][j].first) {
              dp[i][j].second = (dp[i][j].second + dp[ni][nj].second) % MOD;
            }
          }
        }
      }

      if (dp[0][0].second == 0) return {0,0};
      return {dp[0][0].first, dp[0][0].second};
    }

    const vector<pair<int,int>> directions = {{1,0},{1,1},{0,1}};
};


/*

maximum sum of numeric characters you can collect
number of such paths that you can take to get that maximum sum


dp[i][j] = dp[i-1][j] + x



*/
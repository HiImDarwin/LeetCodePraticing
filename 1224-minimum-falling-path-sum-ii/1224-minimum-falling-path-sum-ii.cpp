class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<int> dp(n,INT_MAX);

      for (int i = 0; i < n; i ++) {
        dp[i] = grid[0][i];
      } 

      for (int i = 0; i < n - 1; i++) {
        pair<int,int> smallest = {INT_MAX, -1}, secondSmall = {INT_MAX, -1};
        for(int j = 0; j < n; j++) {
          if (dp[j] < smallest.first) {
            secondSmall = smallest;
            smallest = {dp[j],j};
          } else if (dp[j] < secondSmall.first) {
            secondSmall = {dp[j],j};
          }
        }
        for(int j = 0; j < n; j++) {
          if(j == smallest.second) {
            dp[j] = grid[i+1][j] + secondSmall.first;
          } else {
            dp[j] = grid[i+1][j] + smallest.first;
          }
        }
      }
      return *min_element(dp.begin(),dp.end());
    }

};
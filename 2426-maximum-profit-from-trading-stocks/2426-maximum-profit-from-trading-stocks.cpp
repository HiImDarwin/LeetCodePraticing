class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
      int n = present.size();
      present.insert(present.begin(),0);
      future.insert(future.begin(),0);
      vector<vector<int>> dp(budget+1,vector<int>(n+1,0));


      for (int i = 0; i <= budget; i++) {
        for (int j = 1; j <= n; j++) {
          dp[i][j] = max(dp[i][j-1],((i - present[j] >=0 ) ? dp[i - present[j]][j - 1] + future[j] - present[j]: 0));
        }
      }
      return dp[budget][n];
    }
};

/*
dp[i][j] is the profit can earn undert i budget and consider j stuck
dp[i][j] = don't buy j dp[i][j-1] 
            buy j dp[i-present[j]][i-1] + future - present

O(budget * stuck size)

*/


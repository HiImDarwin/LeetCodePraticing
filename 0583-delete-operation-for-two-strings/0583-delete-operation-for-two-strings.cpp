class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        //finding longest subsequence
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for (int i = 1; i <= m; ++i) {
          for (int j = 1; j <= n ; ++j) {
            dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
        return  m + n - dp[m][n]*2;
    }
};
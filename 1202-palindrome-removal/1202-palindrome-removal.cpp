class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++) {
          dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
          for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i][j-1] + 1;
            for (int k = i; k < j; ++k) {
              int prev = k - 1 >= i ? dp[i][k-1] : 0;
              int post = k + 1 <= j - 1 ? dp[k+1][j-1] : 1;
              if (arr[k] == arr[j]) {
                dp[i][j] = min(dp[i][j], prev + post);
              }
            }
          }
        }
        return dp[0][n-1];
    }
};




/*


[i X X X j]
 k
dp[i][j] = if (arr[i] == arr[j]) dp[i+1][j-1];
           if (arr[i] != arr[j]) dp[i+1][j-1] + 2;

*/
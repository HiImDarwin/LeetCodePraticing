class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      int size = strs.size();
      vector<int> zeroCount(size, 0), oneCount(size, 0);
      for (int i = 0; i < size; i++) {
        string& s = strs[i];
        for (const char& c : s) {
          if (c == '1') {
            oneCount[i]++;
          } else {
            zeroCount[i]++;
          }
        }
      }

      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

      for (int i = 0; i < size; i++) {
        for (int j = m; j >= zeroCount[i]; j--) {
          for (int k = n; k >= oneCount[i]; k--) {
            dp[j][k] = max(dp[j][k], dp[j - zeroCount[i]][k - oneCount[i]] + 1);
          }
        }
      }

      return dp[m][n];
    }
};


/*



*/


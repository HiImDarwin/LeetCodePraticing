class Solution {
public:
//     int countVowelStrings(int n) {
//       return comb(n+4,4);
//     }
// private: 
//     long long comb(int m, int n) {
//       if (n > m) return 0;
//       long long res = 1;
//       if (n > m - n) n = m - n;
//       for (int i = 0; i < n; i++) {
//         res *= (m-i);
//         res /= (i+1);
//       }
//       return res;
//     }

    int countVowelStrings(int n) {
      vector<vector<int>> dp(n+1, vector<int>(5,0));
      for (int i = 0; i < 5; i++) {
        dp[1][i] = 1;
      }
      for (int i = 2; i <= n; i++) {
        for (int vow = 0; vow < 5; vow++) {
          for (int j = vow; j >= 0; j--) {
            dp[i][vow] += dp[i-1][j];
          }
        }
      }

      int res = 0;
      for (int i = 0; i < 5; i++) {
        res += dp[n][i];
      }
      return res;
    }
};

/*

dp[n][a] = dp[n-1][a]
7
XXXXX

*/
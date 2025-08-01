class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      int m = str1.length();
      int n = str2.length();
      
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          //str1[i] == str2[j]
          if(str1[i-1] == str2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + str1[i-1];
          } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
      string lcs;
      int i = m, j = n;
      while(i > 0 && j > 0) {
        if(str1[i - 1] == str2 [j - 1]) {
          lcs += str1[i - 1];
          --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
          i--;
        } else {
          j--;
        }
      }
      reverse(lcs.begin(), lcs.end());
      string res;
      i = j = 0;
      for (char c : lcs) {
        while(str1[i] != c) res += str1[i++];
        while(str2[j] != c) res += str2[j++];
        res += c;
        i++; j++;
      }
      res += str1.substr(i);
      res += str2.substr(j);
      return res;
    }

};
class Solution {
public:
    // long long numberOfWays(string s) {
    //   int n = s.length();
    //   long long prefZero = 0, suffZero =0, suffOne = 0, prefOne = 0;
    //   for (int i = 0; i < n; ++i) {
    //     if (s[i] == '0') {
    //       suffZero++;
    //     } else {
    //       suffOne++;
    //     }
    //   }
    //   long long res = 0;
    //   for (int i = 0; i < n; ++i) {
    //     if (s[i] == '1') {
    //       res += prefZero * suffZero;
    //       prefOne++;
    //       suffOne--;
    //     } else {
    //       res += prefOne * suffOne;
    //       prefZero++;
    //       suffZero--;
    //     }
    //   }
    //   return res;
    // }
    long long dp[100001][4][2];
    long long numberOfWays(string s) {
      int n = s.size();
      s = "#" + s;
      //還沒選擇任何字元的狀況，結尾是0/1都是有效的狀態
      dp[0][0][0] = 1;
      dp[0][0][1] = 1;

      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
          for (int k = 0; k < 2; ++k) {
           // not chosing i elment
           dp[i][j][k] = dp[i-1][j][k];
           if(j >= 1 && s[i] - '0' == k) {
            dp[i][j][k] += dp[i-1][j-1][1-k];
           }
          }
        }
      }
      return dp[n][3][0] + dp[n][3][1];
    }
};

/*
brute force
for each position consider  how many 1 and 0 before him

maintain a sliding window


dp[0][index]
dp[1][index]

"001101"



*/


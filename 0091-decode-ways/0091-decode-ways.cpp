class Solution {
  public:
    // int numDecodings(string s) { 
    //   int n = s.length();
    //   vector<int> dp(n+1,0);
    //   dp[0] = 1;
    //   dp[1] = 1;
    //   if(s[0] == '0') return 0;
    //   for(int i = 2; i　<=　n; ++i) {
    //     if(s[i-1] == '0' && s[i-2] != '1' && s[i-2] != '2') return 0;
    //     if(s[i-1] == '0' && (s[i-2] == '1' || s[i-2] == '2')) dp[i] = dp[i-2];
    //     if(s[i-1] != '0') dp[i] += dp[i-1];
    //     if(s[i-1] != '0' && s[i-2] != '0' && (s[i-2]-'0')*10 + s[i-1] - '0' < 27) dp[i] += dp[i-2];
    //   }
    //   return dp[n];
    // }
    int numDecodings(string s) {
      int n = s.length();
      if( n == 0 || s[0] == '0') return 0;
      vector<int> dp(n+1,0);
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i <= n; ++i) {
        if(s[i - 1] != '0') dp[i] += dp[i-1];
        int twoDigit = (s[i-2] - '0')*10 + s[i - 1] - '0';
        if (twoDigit > 9 && twoDigit < 27) dp[i] += dp[i-2];
      }
      return dp[n];
    }

};
class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
      int p1 = primeOne, p2 = primeTwo;
      vector<int> dp(p1*p2+1);
      dp[0] = 1;
      int res = 0;
      for (int i = 1; i <= p1 * p2; ++i) {
        dp[i] = (i >= p1 && dp[i-p1] ) || (i >= p2 && dp[i-p2]);
        if(dp[i] == 0) res = max(res,i);
      }
      return res;
    }
};


/*

- - - - 5
- - - - - - 7

5 2
11 2 8 4 5
*/
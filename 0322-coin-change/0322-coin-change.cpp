class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount+1,INT_MAX); 
      dp[0] = 0;
      for (int i = 1; i <= amount; i++) {
        for (int& money : coins) {
          if(i - money < 0 || dp[i - money] == INT_MAX) {
            continue;
          }
          dp[i] =min(dp[i], dp[i-money] + 1);
        }
      }
      return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


/*
dp[n] = fewest number of coins to make up n

*/
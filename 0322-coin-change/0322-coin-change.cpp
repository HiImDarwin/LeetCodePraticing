class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount + 1, INT_MAX / 2);
      dp[0] = 0;
      for (int i = 1; i <= amount; i++) {
        for (int& coinAmount : coins) {
          if (i - coinAmount < 0) {
            continue;
          } 
          dp[i] = min(dp[i], dp[i - coinAmount] + 1);
        }
      }
      return dp[amount] == INT_MAX / 2 ? -1 : dp[amount];
    }
};

/*
每個 coin 我都能用多次

for (i = 1 ~ amount)
  for (coins)
    dp[i] =min(dp[i],dp[i - coinAmount] + 1);
  
*/
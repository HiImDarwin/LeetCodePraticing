class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<unsigned long long> dp(amount + 1, 0);
      dp[0] = 1;


      for (int& coinAmount : coins) {
        for (int i = 1; i <= amount; i++) { 
          if (i - coinAmount < 0) {
            continue;
          }
          dp[i] += dp[i - coinAmount];
        }
      }
      return dp.back();
    }
};

/*
number of combination
  for (amount)


  1 2 
  2 1

*/
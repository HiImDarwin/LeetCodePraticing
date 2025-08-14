class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<uint64_t> dp(amount+1,0); 
      dp[0] = 1;
      for (int t = 0; t < coins.size(); t++) {
        for (int i = coins[t]; i <= amount; ++i) {
            dp[i] += dp[i - coins[t]];
        }
      }
      return (int)dp[amount];
    }

};



/*
  number of combinations that make up that amount



  1 3 5

  1 2 3 4 5 6 7 8 
  1 1 2 3


  1111
  為了避免 131 113 這種重覆情況
  我們使用1 3必須按照順序 就可以避免這問題
  那怎麼做到 讓外圈for 以coin value 為優先
*/

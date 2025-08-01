class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      int n =nums.size();
      vector<vector<int>> dp(n + 1, vector<int>(3, 0));
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j ++) {
          dp[i][j] = dp[i-1][j];
          if (j +1  == nums[i - 1]) {
            for (int x = 0; x < j; x++) {
              dp[i][j] = max(dp[i][j], dp[i-1][x]);
            }
            dp[i][j]++;
          }
        }
      }
      return n - max({dp[n][0],dp[n][1],dp[n][2]});
    }
};


/*
 [2,1,3,2,1]
  dp[i][j] 

  dp[0][0] = 0;
  dp[0][1] = 1;
  dp[2][2] = 0;

  dp[1][0] = dp[0][0] + (nums[i] == 1)
  dp[1][1] = max(dp[0][0], dp[0][1]) + 1
  dp[1][2] = max(dp[0][0], dp[0][1], dp[0][2]) + 1

  dp[][0] =
  dp[][1] =
  dp[][2] = 

  dp[][0] =
  dp[][1] =
  dp[][2] = 

  i is the index , 
  j is the biggest num and 
  dp[i][j] is the lenght
  dp[1][1] = max(dp[0][1]) +1;
  dp[1][2] = max(dp[0][1], dp[0][2]) + 1;

*/
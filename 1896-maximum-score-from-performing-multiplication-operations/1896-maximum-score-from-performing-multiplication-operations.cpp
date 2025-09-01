class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int len = nums.size();
      int m = multipliers.size();
      vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MIN/2));
      dp[0][0] = 0;
      
      for (int l = 1; l <= m; l++) {
        for (int left = 0; left <= l ; left++) {
          int right = l - left;
          if (left > 0)
            dp[l][left] = max(dp[l][left],
                            dp[l - 1][left - 1] + multipliers[l - 1] * nums[left - 1]);
          if (right > 0)
            dp[l][left] = max(dp[l][left], 
                            dp[l - 1][left] + multipliers[l - 1] * nums[len - right]); 
        }
      }
      
      int res = INT_MIN;
      for (int i = 0; i <= m; i++) {
        res = max(res, dp[m][i]);
      }
      return res;   
    }
};



/*

dp[len][left] = max(dp[len-1][left] + multipliers[len]*nums[n-(len-left)-1], dp[len-1][left-1] + multipliers[len]*nums[len])
1. state 設計
2. state 轉移


*/
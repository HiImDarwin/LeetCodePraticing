class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(maxAmount+1,vector<int>(maxCoupons+1,0)));

        int res = 0;
        for (int i = 1; i <= n; ++i) {
          for (int j = 0; j <= maxAmount; j++) {
            for (int k = 0; k <= maxCoupons; k++) {

              dp[i][j][k] = dp[i-1][j][k];
              if (j >= price[i-1]) {
                int prev =  dp[i-1][j-price[i-1]][k];
                dp[i][j][k] = max(dp[i][j][k], prev + tastiness[i-1]);
              }
              if (k >= 1 && j >= price[i-1] / 2) {
                int prev = (i == 0) ? 0 : dp[i - 1][j - price[i-1] / 2][k - 1];
                dp[i][j][k] = max(dp[i][j][k], prev + tastiness[i-1]);
              }
              res  = max(res,dp[i][j][k]);
            }
          }
        }
        return res;
    }
};



/*
dp[i][j][k]
i: item index 
j: price already spend
k: uesd k coupon


recursive + memo


*/




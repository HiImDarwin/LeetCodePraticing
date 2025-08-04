class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
      vector<int> dp(n+1,-1);
      dp[0] = 0;
      sort(offers.begin(), offers.end(),[](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
      });
      int offerIdx = 0;
      for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        while (offerIdx < offers.size() && offers[offerIdx][1] == i) {
          int start = offers[offerIdx][0];
          int gold = offers[offerIdx][2];
          dp[i+1] = max(dp[i+1], dp[start] + gold);
          offerIdx++;
        }
      }
      return dp[n];
    }
};
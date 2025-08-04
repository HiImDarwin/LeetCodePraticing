class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](vector<int>& a, vector<int>& b){
          return a[1] < b[1];
        });
        vector<long long> dp(n+1,0);
        int passengerIdx = 0;
        for(int i = 1; i <= n; ++i) {
          dp[i] = dp[i-1];
          while (passengerIdx < rides.size() && rides[passengerIdx][1] == i) {
            int start = rides[passengerIdx][0];
            int tip = rides[passengerIdx][2];
            dp[i] = max(dp[i], dp[start] + i - start + tip);
            passengerIdx++;
          }
        }
        return dp[n];
    }
};
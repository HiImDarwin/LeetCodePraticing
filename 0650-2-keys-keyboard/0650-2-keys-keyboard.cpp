class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for(int size = 1; size < n; ++size){
          for(int i = size * 2; i <= n; i+=size){
            if (i % size != 0) continue;
            dp[i] = min(dp[i], (dp[size]+1) + (i-size)/size);
          }
        }
        return dp[n];
    }
};
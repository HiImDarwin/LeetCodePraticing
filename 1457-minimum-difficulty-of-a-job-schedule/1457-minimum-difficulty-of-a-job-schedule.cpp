class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
      int n = jobDifficulty.size();
      if (n < d) return -1;
      jobDifficulty.insert(jobDifficulty.begin(),0);
      vector<vector<int>> dp(d+1,vector<int>(n+1,INT_MAX/2));
      dp[0][0] = 0;
      for (int i = 1; i <= d; i++) {
        for (int k = 1; k <= n; k ++) {
          int maxi = jobDifficulty[k];
          for (int j = k; j - i >= 0; j--) {
            maxi = max(maxi,jobDifficulty[j]);
            dp[i][k] = min(dp[i][k], maxi + dp[i-1][j-1]);
          }
        }
      }
      return dp[d][n];
    }
};


/*
Return the minimum difficulty of a job schedule.
dp[i][j] minimum difficulty of a job schedule in i days



dp[i][j] = min(dp[i-1][k-1]+ max(k:j)); 

find the left maximum val index of j (or itself is maximum)

XXXXXXXX


1 1 6 6 2 2 



*/
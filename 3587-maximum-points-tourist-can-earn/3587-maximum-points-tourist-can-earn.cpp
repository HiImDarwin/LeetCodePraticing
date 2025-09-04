class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
      vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(n,vector<int>(2,INT_MIN)));

      for (int city = 0 ; city < n; city++) {
        dp[0][city][0] = 0;
      }

      for (int day = 1; day <= k ; ++day) {
        for (int city = 0 ; city < n; city++) {
          for (int i = 0; i < n; i++) {
            if (i == city) continue;
            dp[day][city][0] = max(dp[day][city][0], 
                                max(dp[day - 1][i][0], dp[day - 1][i][1]) + travelScore[i][city]);
          }
          for (int d = 1; d <= day; d++) {
            dp[day][city][1] = max(dp[day][city][1],
                                   dp[day-d][city][0] + stayScore[d-1][city]);
          }
        }
      }

      int maxScore = 0;
      for (int i = 0; i < n ; i++) {
        maxScore = max({maxScore, dp[k][i][0], dp[k][i][1]});
      }

      return maxScore;
    }
};

/*
dp[k][i][0]    maximum score if u arrive city i in day k
dp[k][i][0]    maximum score if u stay in city i in day k



dp[k][i][0]   = max(dp[k-1][j][0],dp[k-1][j][0]) + travelScore[j][i]
dp[k][i][1]. = max(dp[k - d][i][0] + stayScore[d][i])
O(KK + KN)

*/
class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
      vector<vector<int>> dp(2,vector<int>(n,INT_MIN));

      for (int city = 0 ; city < n; city++) {
        dp[0][city] = 0;
      }

      for (int day = 1; day <= k ; ++day) {
        fill(dp[1].begin(), dp[1].end(), INT_MIN);
        for (int city = 0; city < n; city++) {
          for (int i = 0; i < n; i++) {
            if (i == city) {
               dp[1][city] = max(dp[1][city], dp[0][city] + stayScore[day - 1][city]);
            }else  {
              dp[1][city] = max(dp[1][city], dp[0][i] + travelScore[i][city]);
            }
          }  
        }
        swap(dp[0],dp[1]);
      }

      int maxScore = INT_MIN;
      for (int i = 0; i < n ; i++) {
        maxScore = max(maxScore, dp[0][i]);
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
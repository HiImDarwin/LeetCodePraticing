class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
      int N = points.size();
      vector<int> dp(1<<N, INT_MAX/3);

      for (int i = 0; i < N; i++) {
        dp[1 << i] = 1;
      }

      for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
          int state = 0;
          state |= 1 << i;
          state |= 1 << j;
          dp[state] = 1;
          for (int k = j + 1; k < N; k++) {
            pair<int,int> vec1 = {points[i][0] - points[j][0],points[i][1] - points[j][1]};
            pair<int,int> vec2 = {points[i][0] - points[k][0],points[i][1] - points[k][1]};
            if (vec1.first*vec2.second - vec1.second*vec2.first == 0) {
              state |= (1 << k);
              dp[state] = 1;
            }
          }
        }
      }

      for (int state = 0; state < 1 << N; state++) {
        for (int subset = state; subset > 0; subset = (subset - 1)& state) {
          dp[state] = min(dp[state], dp[subset] + dp[state - subset]);
        }
      }

      return dp[(1 << N) - 1];
    }
};


/*


11111
11100 00011
11000 00111

*/
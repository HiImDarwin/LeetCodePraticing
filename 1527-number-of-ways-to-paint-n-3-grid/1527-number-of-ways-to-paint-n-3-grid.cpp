class Solution {
public:
    int numOfWays(int n) {
      int MOD = 1e9+7;
      vector<int> validState;
      for (int state = 0; state < 27; state++) {
        int stateCopy = state;
        vector<int> colorArrange;
        bool notValid = false;

        for (int i = 0; i < 3; ++i) {
          int color = stateCopy%3;
          if (!colorArrange.empty() && colorArrange.back() == color) {
            notValid = true;
            break;
          }
          colorArrange.push_back(color);
          stateCopy /= 3;
        }
        if (notValid) continue;
        validState.push_back(state);
      }
      int stateNum = validState.size();
      vector<vector<int>> validConnect(stateNum);

      for (int i = 0; i < stateNum; i++) {
        for (int j = i + 1; j < stateNum; j++) {
          int state1 = validState[i];
          int state2 = validState[j];
          bool notValid = false;
          for (int idx = 0; idx < 3; idx++) {
            int color1 = state1%3;
            int color2 = state2%3;
            if (color1 == color2) {
              notValid = true;
              break;
            }
            state1 /= 3;
            state2 /= 3;
          }
          if (notValid) continue;
          validConnect[i].push_back(j);
          validConnect[j].push_back(i);
        }
      }
      //dp[row][state]
      vector<vector<int>> dp(n,vector<int>(stateNum,0));

      for (int i = 0; i < stateNum; i++) {
        dp[0][i] = 1;
      }

      for (int row = 1; row < n; row++) {
        for (int idx = 0; idx < stateNum; idx++) {
          for (auto& validIdx :validConnect[idx]) {
            dp[row][idx] = (dp[row][idx] + dp[row-1][validIdx]) % MOD;
          }
        }
      }

    
      int res = 0;
      for (int i = 0; i < stateNum; i++) {
        res = (res + dp[n-1][i]) % MOD;
      }

      return res;
    }
};
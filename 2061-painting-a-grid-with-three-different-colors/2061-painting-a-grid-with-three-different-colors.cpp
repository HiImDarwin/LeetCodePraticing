class Solution {
public:
    int colorTheGrid(int m, int n) {
      int MOD = 1e9+7;
      vector<int> validState;
      for (int state = 0; state < pow(3,m); state++) {
        int stateCopy = state;
        vector<int> colorArrangeMent;
        bool notValid = false;
        for (int i = 0; i < m; i++) {
          int color = stateCopy%3;
          if (!colorArrangeMent.empty() && colorArrangeMent.back() == color) {
            notValid = true;
            continue;
          }
          colorArrangeMent.push_back(color);
          stateCopy /= 3;
        }
        if (notValid) continue;
        validState.push_back(state);
      }
      int k = validState.size();
      vector<vector<int>> stateTransfer(k);

      for(int i = 0; i < k; i++) {
        for (int j = i + 1; j <k; j++) {
          int state1 = validState[i];
          int state2 = validState[j];
          bool notValid = false;
          for (int idx = 0; idx < m; idx++) {
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
          stateTransfer[i].push_back(j);
          stateTransfer[j].push_back(i);
        }
      }

      // dp[col][state]
      vector<vector<int>> dp(n,vector<int>(k,0));
      for (int i = 0; i < k; i++) {
        dp[0][i] = 1;
      }

      for (int row = 1; row < n; row++) {
        for (int i = 0; i < k; i++) {
          for (auto& idx : stateTransfer[i]) {
            dp[row][i] = (dp[row][i] + dp[row-1][idx]) % MOD;
          }
        }
      }

      int res = 0;
      for (int i = 0; i <k; i++) {
        res = (res + dp[n-1][i]) % MOD;
      }
      return res;
    }
};


/*

dp[m][n] = dp[m-1][n][color] * dp[m][n-1][color]

行：5  >> 代表狀態壓縮 ３＾５種可能
列：1000
狀態壓縮的動態規劃 通常狀態是內回圈
dp[i][01210] = ?
Time Complexity
m * 3^n * 3^n 這時間複雜度還是太高了 5*1e7
因此要怎麼降低複雜度？
將3^n當中不合法的組合拿掉
3^5 > 合法只有48種 3*2*2*2*2  
*/
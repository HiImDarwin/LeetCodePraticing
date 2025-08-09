class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
      sort(cuts.begin(), cuts.end());
      cuts.insert(cuts.begin(),0);
      cuts.push_back(n);
      int m = cuts.size();

      vector<vector<int>> dp(m, vector<int>(m,INT_MAX));
      for (int i = 0; i+1 <m; i++) {
        dp[i][i+1] = 0;
      }

      for (int len = 3; len <= m; len++) { // 區間長度 至少兩個端點
        for (int i = 0; i + len - 1 < m; i++){ // 區間起點 是i 區間終點 i+len-1 那麼就間點就是
          int j = i+len-1;
          for (int k = i + 1; k < j; k++) { //所有區間中間點
            dp[i][j] = min(dp[i][j], cuts[j]-cuts[i] + dp[i][k] + dp[k][j]);
          }
        }
      }
      
      return dp[0][m-1];
    }
};


/*
dp[i][j]: i j 表示第i 與第 j cut 並且在 i j 中間找一個k 讓他代價最小
dp[i][j] = min(cut[i]-cut[j] + dp[i][k] + dp[k][j]); 
需要把 0 與 n 也加入cuts


X X X X  4
X X  X X 2 2
X  X  X  X

X X X X  4
X X X  X 3 
X X  X  X 2
X X X X
*/
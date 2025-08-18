class Solution {
  int dp[102][102];
  int sufSum[102];
public:
    int stoneGameII(vector<int>& piles) {
      int n = piles.size();
      sufSum[n] = 0;
      for (int i = n-1; i >=0; --i) {
        sufSum[i] = sufSum[i+1] + piles[i];
      }
      return decision(0,1, piles);
    }


    int decision(int start, int M,  vector<int>& piles) {
      if (start >= piles.size()) {
        return 0;
      }
      if (dp[start][M] != 0) {
        return dp[start][M];
      }
      int range = M * 2;
      int sum = 0;
      for (int x = 1; x <= 2*M && start + x - 1 < piles.size(); x++) {
        sum += piles[start + x - 1];
        // 你不清楚前面幾輪的情況，你會收到 對手這回合之後內拿到的最大值
        // 那你要怎麼知道自己的最大值？
        // suffixSum
        int opponentSum = decision(start + x, max(M,x) , piles);
        dp[start][M] = max(dp[start][M], sum + sufSum[start+x] - opponentSum);
      }
      return dp[start][M];
    }
};

/*
訂定一個決策函數
我們設計決策函數時，希望對手的收益最小化


從上往下 遞迴
欉下往上 DP


M = 1
X <= 2M
*/
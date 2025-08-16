class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
      unordered_map<int,int> memo;
      return dfs(x, y , memo);
    }

    int dfs(int x, int y, unordered_map<int, int>& memo) {
      if (x <= y) return y-x;
      if (memo.count(x)) {
        return memo[x];
      }
      int res = x - y;
      int divideEleOp = 0;
      int divideFiveOp = 0;
      int elevenStep = INT_MAX/2, FiveStep = INT_MAX/2, basicStep;

      if (x > y) {
        if (x%11 <= 5) {
          divideEleOp += x%11;
          elevenStep = dfs((x - x%11)/11, y , memo) + 1;
        } else {
          divideEleOp += 11 - (x%11);
          elevenStep = dfs((x + (11 - (x%11)))/11, y , memo) + 1;
        }

        if (x%5 <= 2) {
          divideFiveOp += x%5;
          FiveStep = dfs((x - x%5)/5, y , memo) + 1;
        } else {
          divideFiveOp += (5 - x%5);
          FiveStep = dfs((x + (5 - x%5))/5, y , memo) + 1;
        }
      }
      basicStep = abs(x - y);
      res = min({divideEleOp + elevenStep,divideFiveOp + FiveStep, basicStep});
      memo[x] = res;
      return res;
    }
};
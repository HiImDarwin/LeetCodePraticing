class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return dfs(n);
    }
    int dfs (int len) {
      if (len == 0) return 1;
      int start  = 9;
      for (int i = 1; i < len; i++) {
        start  = start * (10 - i);
      }
      return start + dfs(len - 1);
    }
};
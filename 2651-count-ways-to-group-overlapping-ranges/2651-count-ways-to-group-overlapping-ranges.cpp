class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
      if (ranges.size() == 0) return 0;

      int MOD = 1e9 + 7;
      int n = ranges.size();
      sort(ranges.begin(), ranges.end());

      vector<vector<int>> newRange;
      int prevStart = ranges[0][0], prevEnd = ranges[0][1];
      for (int i = 1; i < n; ++i) {
        int start = ranges[i][0];
        int end = ranges[i][1];
        if (start <= prevEnd) {
          prevEnd = max(end, prevEnd);
        } else {
          newRange.push_back({prevStart,prevEnd});
          prevStart = start;
          prevEnd = end;
        }
      }
      newRange.push_back({prevStart,prevEnd});

      long long res = 1;
      for (int i = 0; i < newRange.size(); i++) {
        res = (res * 2) % MOD;
      }
      return res;
    }
};


/*

[] [] [] [] [] []

*/
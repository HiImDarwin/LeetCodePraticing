class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      vector<vector<int>> intervals;
      for (int i = 0; i <= n; i++) {
        intervals.push_back({i - ranges[i],i + ranges[i]});
      }
      sort(intervals.begin(), intervals.end());
      // sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
      //   if (a[0] == b[0]) {
      //     return a[1] > b[1];
      //   }
      //   return a[0] < b[0];
      // });

      int right = 0;
      int idx = 0;
      int tapCount = 0;
      while (idx <= n) {
        if (right >= n) {
          break;
        }
        if (right < intervals[idx][0]) {
          return -1;
        }
        int currMaxRight = intervals[idx][1];
        while (idx + 1 <= n && intervals[idx + 1][0] <= right) {
          currMaxRight = max(currMaxRight, intervals[idx + 1][1]);
          idx++;
        }
        right = currMaxRight;
        tapCount++;
        idx++;
      }

      return right < n ? -1 : tapCount;
    }
};
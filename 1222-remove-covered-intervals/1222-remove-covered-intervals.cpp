class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) {
          return a[1] > b[1];
        }
        return a[0] < b[0];
      });

      int n = intervals.size();
      int idx = 0;
      int deleteCount = 0;
      while (idx < n) {
        int left = intervals[idx][0];
        int right = intervals[idx][1];
        while (idx + 1 < n && intervals[idx + 1][1] <= right) {
          deleteCount++;
          idx++;
        }
        idx++;
      }
      return n - deleteCount;   
    }
};



/*
   a. b
   XXXX

  c     d
  xxxxxxx


*/
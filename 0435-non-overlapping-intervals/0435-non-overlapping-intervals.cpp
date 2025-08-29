class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n = intervals.size();
      sort(intervals.begin(), intervals.end());
      int prevEnd = intervals[0][1];
      int res = 0;
      for (int i = 1; i < n; ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (start < prevEnd) {
          prevEnd = min(end, prevEnd);   
          res++;
        } else {
          prevEnd = end;
        }
        
      }

      return res;
    }
};


/*

 XXX
  XXXX
       XX
          xx

XXX
  XXXX

XXXXXX
  XX


minimum number of intervals you need to remove
always remove the one with larger length

XX XX XX XX XX XXXX
 XXXXXXXXXXXXXXXX

*/
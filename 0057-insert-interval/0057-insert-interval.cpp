class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int N = intervals.size();
      int newStart =  newInterval[0];
      int newEnd = newInterval[1];
      vector<vector<int>> res;

      for (int i = 0; i < N; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (end < newStart) {
          res.push_back({start, end});
        } else if ((start < newEnd && end >= newStart ) || 
                    (newStart <= start && newEnd >= start)) {
          newStart = min(start,newStart);
          newEnd = max(end, newEnd);
        } else if (newEnd < start) {
          res.push_back({newStart, newEnd});
          newStart = start;
          newEnd = end;
        }
      }
      res.push_back({newStart, newEnd});
      return res;
    }
};


/*

XXX XXX XXX XXX
  XXXX

XXX   XXX XXX XXX
  XXXX


XXX     XXX XXX XXX
  XXXX

XXX        XXX XXX XXX
     XXXX

XXXXXX XXX XXX XXX
  XX



*/
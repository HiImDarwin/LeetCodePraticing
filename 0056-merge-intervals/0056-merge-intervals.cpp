class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      int N = intervals.size();
      vector<vector<int>> res;
      int start = intervals[0][0];
      int end = intervals[0][1];
      for (int i = 1; i < N ; i++) {
        int nextStart = intervals[i][0];
        int nextEnd = intervals[i][1];
        if (nextStart > end) {
          res.push_back({start,end});
          start = nextStart;
          end = nextEnd;
        } else {
          end = max(nextEnd,end);
        }
      }
      res.push_back({start, end});
      return res;  
    }
};



/*

XXXXX
      XXXXX
   XXXX 

XXXXXXX
  XXX

XXXX
 XXX



*/
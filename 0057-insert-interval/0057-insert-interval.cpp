class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res;
      vector<int> seg = newInterval;
      bool notPush = true;
      for(int i = 0; i < intervals.size(); i++) {
        if (seg[0] > intervals[i][1]) {
          res.push_back(intervals[i]);
        } else if (seg[1] < intervals[i][0] && notPush) {
          res.push_back(seg);
          res.push_back(intervals[i]);
          notPush = false;
        } else if (seg[1] < intervals[i][0]) {
          res.push_back(intervals[i]);
        } else {
          seg[0] = min(seg[0], intervals[i][0]);
          seg[1] = max(seg[1], intervals[i][1]);
        }
      } 
      if (notPush) {
        res.push_back(seg);
      }

      return res;
    }
};

//.   [.   ]   [.   ]
/*
    [.  ]
           [.   ]
                  [.   ]
     [                 ]
             []


     we got 4 satuation

*/
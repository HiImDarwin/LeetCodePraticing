class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
      int removeFront = toBeRemoved[0];
      int removeEnd = toBeRemoved[1];
      vector<vector<int>> res;
      for(auto& interval: intervals) {
        int front = interval[0], end = interval[1];
        if (front < removeFront) {
          res.push_back({front, min(end, removeFront)});
        }
        if (removeEnd < end) {
          res.push_back({max(front,removeEnd), end});
        }
      }
      return res;
    }
};


/*
XXX XXX XXX XXXXXX
  --------


not overlap front
  rmoved end <= front

overlap in front
 front > romove front && front < rmoved end

overlap whole segment


overlap in end
 front < remove front && end <remove end
not overlap end
  end <= rmoveFront
*/
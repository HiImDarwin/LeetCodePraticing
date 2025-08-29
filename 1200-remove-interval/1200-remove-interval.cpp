class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
      int removeFront = toBeRemoved[0];
      int removeEnd = toBeRemoved[1];
      vector<vector<int>> res;
      for(auto& interval: intervals) {
        int front = interval[0];
        int end = interval[1];

        if (removeEnd <= front || end <= removeFront) {
          res.push_back({front,end});
        } else  {
          if (front < removeFront){
            res.push_back({front, removeFront});
          }
          if (removeEnd < end) {
            res.push_back({removeEnd, end});
          }
      
        }
      
        //   if (removeFront <= front && front < removeEnd && removeEnd < end) {
        //   res.push_back({removeEnd, end});
        // } else if (removeFront <= front && end <= removeEnd) {
        //   continue;
        // } else if (front < removeFront && removeEnd < end) {
        //   res.push_back({front, removeFront});
        //   res.push_back({removeEnd, end});
        // } else if (front < removeFront &&  removeFront < end && end <= removeEnd) {
        //   res.push_back({front, removeFront});
        // }
       
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
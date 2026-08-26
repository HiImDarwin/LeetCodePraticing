class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 1) {
      return intervals;
    }
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });
    vector<int> tmp(2);
    tmp[0] = intervals[0][0];
    tmp[1] = intervals[0][1];
    
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] > tmp[1]) {
        res.push_back(tmp);
        tmp[0] = intervals[i][0];
        tmp[1] = intervals[i][1];
      } else {
        //tmp[0] = min(tmp[0], intervals[i][0]);
        tmp[1] = max(tmp[1], intervals[i][1]); 
      }
    }


    res.push_back(tmp);


    return res;
  }
};


// [ ] [ ] [ ] [  ] [  ]
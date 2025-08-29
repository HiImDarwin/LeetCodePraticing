class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int n = points.size();
      sort(points.begin(), points.end());
      int res = 0;
      int idx = 0;
      while (idx < n) {
        int left = points[idx][0];
        int right = points[idx][1];
        while (idx + 1 < n && points[idx + 1][0] <= right) {
          left = max(left, points[idx + 1][0]);
          right = min(right, points[idx + 1][1]);
          idx++;
        }
        idx++;
        res++;
      }

      return res;
    }
};


/*
   XXXX
 XX
 XXX
XXXXX


*/
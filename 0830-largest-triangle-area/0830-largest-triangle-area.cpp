class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
      int n = points.size();
      double res = 0;
      for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n - 1; j++) {
          for (int k = 2; k < n; k++) {
            pair<double,double> v1 = {points[j][0] - points[i][0], points[j][1] - points[i][1]};
            pair<double,double> v2 = {points[k][0] - points[i][0], points[k][1] - points[i][1]};
            double area = abs(v1.first * v2.second - v1.second * v2.first) / 2;
            res = max(res, area);
          }
        }
      }
      return res;
    }
};


/*
calculate area with vector (x1, y1) (x2, y2)
|x1*y2 - y1*x2| 
*/ 
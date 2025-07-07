class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n = points.size();
      if(n == 1) return 1;
      int res = 1;
      for(int i = 0; i < n; ++i) {
        map<pair<int,int>, int> count;
        int samePoint = 0;
        int vertical = 0;
        for(int j = 0; j < n; ++j) {
          if(i == j) continue;
          int dx = points[i][0] - points[j][0];
          int dy = points[i][1] - points[j][1];
          if(dx == 0 && dy == 0) {
            samePoint++;
          } else if  (dy == 0) {
            vertical++;
          } else {
            int a = dx/gcd(dx,dy);
            int b = dy/gcd(dx,dy);
            count[{a,b}]++;
          }
        }
        res = max(res, vertical + samePoint + 1);
        for (auto x : count) {
          res = max(res, x.second + samePoint + 1);
        }
      }
      return res;
    }
};



/*
for any two point
cal the slope of it and put into hash map


how to deal with the floating point? 
so we can't use the way how it goes

Way 1

(a b) (c d) (e f)
c-a / d-b  ==  e-1 / f-b
c-a * f-b == e-1 * d-b then we can pass the floating point accurency problem

Way 2
(a b) (c d)

dx = c-a
dy = d-b
find the gcd(dx, dy)
x = gcd/dx
y = gcd/dy

for every  point on the line will have the same x and y

cornor case
1. dy = 0 horizental line
2. dx = 0 vertical line


question
1. node number?
2. node value range?
3. duplicate node in nums?

*/


class Solution {
public:
    double helper (double line, vector<vector<int>> & squares) {
      double aAbove = 0, aBelow =0;
      int n = squares.size();
      for (int i = 0; i < n; ++i) {
        int x = squares[i][0], y = squares[i][1];
        int l = squares[i][2];
        double total = (double) l*l;
        if(line <= y) {
          aAbove += total;
        } else if( line >= y+l) {
          aBelow += total;
        } else {
          double aboveHeight = (y+l) - line;
          double belowHeight = line - y;
          aAbove += l*aboveHeight;
          aBelow += l*belowHeight;
        }      
      }
      return aAbove -aBelow;
    }
    double separateSquares(vector<vector<int>>& squares) {
      double lo = 0, hi = 2*1e9;

      for(int i = 0; i < 60; i++) {
        double mid = (lo + hi) / 2.0;
        double diff = helper(mid, squares);

        if(diff > 0) lo = mid;
        else hi = mid;
      }

      return hi;
    }
};


/*
so we want to find the middle point of area
we can push the square into 1 D to view it

              |    |
     |     |  |    |
--------------------------------------------- y
              +l +l +l     

the length of x y is too large, so we can't use array for prefix sum
i will use weight average to count it

So we y range is 0 ~ (1e9+1e9) = 2*1e9
and we need our solution 1e-5 actual answer

2*1e9 / 2^k = 1e-5

2^k = 2*1e14 
0.301*k  = 0.301+14
 k = 47.xxxx




question 
boundary of x and y

Find the minimum y-coordinate value > can't use weight average
*/
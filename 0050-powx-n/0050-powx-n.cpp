class Solution {
public:
    double myPow(double x, int n) {
      long long powNum = n;
      if (n < 0) {
        x = 1 / x;
        powNum = -powNum;
      }
      return fastPow(x, powNum);
      
    }

    double fastPow(double x, long long n) {
      if (n == 0) return 1.0;
      double y = fastPow(x, n/2);
      return (n % 2 == 0) ? y * y : y * y * x;
    }

};
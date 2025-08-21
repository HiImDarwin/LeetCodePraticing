
#include <cmath>
class Solution {
public:
    int arrangeCoins(int n) {
      long long m = n;
      for (long long target = sqrt(2*m)-1; target < sqrt(2*m); target++) {
        if (target * (target + 1) <= 2 * m && 2 * m < (target + 1) * (target + 2)) {
          return target;
        }
      }
      return -1;
    }
};


/*
(1 + row) * row / 2;
brute force


binary Search

(1 + row) * row <= n*2 < (row+1) * (row + 2)
k^2 + k <= n*2 < (k+1) * (k+2)

k^2 < 2n < (k+2)^2

sqrt(2n)- 2 <  k < sqrt(2n) can only be 1 num;
*/
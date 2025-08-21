class Solution {
public:
    int consecutiveNumbersSum(int n) {
      int res = 0;

      for (int numCount = 1; numCount * (numCount + 1) / 2 <= n; ++numCount) {
        if (numCount%2 == 1 && n % numCount == 0) {
          res++;
        } else if (numCount%2 == 0 && n % numCount == numCount/2) {
          res++;
        }
      }
      return res;
    }
};


/*

sliding window

12345 = 15
1 num
n
n%2 == 1

n%3 == 0

n % 5 == 0


1 2 3 4 = 10

1 2 3 4 5 6 = 21%6

2 3 4 5 = 14 % 4 = 2
*/ 
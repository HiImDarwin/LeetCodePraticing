class Solution {
public:
    int minOperations(int n) {
      int res = 0;
      while (n > 0) {
        if ((n & 3) == 3) {
          n++;
          res++;
        } else {
          res += n & 1;
          n >>= 1;
        }
      }
      return res;
    }
};


/*
38
 10110

42
 101010

40
 100100
 
 0110110

continus 1 >= 2 2 operation
only 1 1 1 operation

54 27 13 6 3 1
110110

*/
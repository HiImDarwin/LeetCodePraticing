class Solution {
public:
    int consecutiveNumbersSum(int n) {
      int res = 0;

      for (int m = 1; 2*n - m*m + m > 0; m++) {
        if ((2*n - m*m + m)%(2*m) == 0){
          res++;
        }
      }
      return res;
    }
};


/*

sliding window

(x + x+m-1 )* m = 2n
x 2n-(m-1)
*/ 
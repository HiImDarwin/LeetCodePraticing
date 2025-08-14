class Solution {
public:
    long long minEnd(int n, int x) {
      int val = n-1;
      long long res = x;
      int xIdx = 0;
      
      while (val>0) {
        if (((1LL << xIdx) & x) == 0) {
          res |= ((1LL & val) << xIdx);
          val >>= 1;
        }
        xIdx++;
      }
      return res;
    }
};

/*
每找到一個0就把val的值跟她做 or

*/
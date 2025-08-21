#include <string>

class Solution {
public:
    int findNthDigit(int n) {
      if (n <= 9) return n;
      int len = 1;
      int BASE = 9;
      while (n > 0) {
        long long sameLenNumCount = 1LL * BASE * pow(10,len-1) * len;
        if (n - sameLenNumCount < 0) {
          break;
        }
        n -= sameLenNumCount;
        len++;
      }
      int num = pow(10,len-1) + ((n-1) / len);
      string s = to_string(num);
      int res = s[(n-1)%len] - '0';
      return res;
    }
};

/*

1 2 3 4 5 6 7 8 9  
10 11 12 13 14 15 16 17 18 19
20

9*1
90*2
900*3
9000*4

9*10^(i-1) * i





*/
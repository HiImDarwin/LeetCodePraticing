class Solution {
public:
    int divide(int dividend, int divisor) {
      long a = (long)dividend;
      long b = (long)divisor;
      long quotient = 0;
      int sign =1;
      if(a < 0) sign *= -1;
      if(b < 0) sign *= -1;
      a = abs(a);
      b = abs(b);

      while(a >= b) {
        long c = b;
        int count = 1;
        while((c<<1) < a) {
          c <<= 1;
          count = count<<1;
        }
        quotient += count;
        a -= c;
      }
      cout << quotient << endl;

      quotient *= sign;
      if(quotient > INT_MAX) 
        return INT_MAX;
      else if(quotient < INT_MIN) 
        return INT_MIN;
      else
        return quotient;
    }
};


/*
can't use * / % 
can use ( +, -, >>, << )
division truncate toward zero 
the quatation will be a point 
quotient * divisor <= dividend

if we use normal add with binary search
it wont get faster if the divisor is small
for example divisor is 1 dividend is 100000

[1 2 3 4 5 6 7 8 9 10 .......  2^16]
[2^8 .... 2^16]

int this case our multiplication already pass the target note sevel time
any

0  1  2  3  4  5  6  7   8   9   10   11   12   13   14  15  16  17 18 .... 31  32
1  2  4  8  16 32 64 128 256 512 1024 2048 4196 8392 ...                          


question
can i use bitwise operation?

*/
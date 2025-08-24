class Solution {
public:
    int countOrders(int n) {
      const int MOD = 1e9+7;
      long long res = 1;
      for (int i = 2 * n; i > 0; i -= 2) {
        res = (res * i * (i-1)/2) % MOD;
      }
      return res;
    }
};


/*
 0 1
C(n,2) + C(n-2,2) + C(n-4,2) + C(n-8,2)

n*n-1*n-2*n-3*...*1
-------------------
2^(n/2)

*/
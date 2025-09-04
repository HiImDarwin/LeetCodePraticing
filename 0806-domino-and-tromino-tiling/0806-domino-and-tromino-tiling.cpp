class Solution {
public:
    int numTilings(int n) {
      if (n == 0) return 1;
      if (n == 1) return 1;
      if (n == 2) return 2;

      vector<int> f(n + 1,0), p(n + 1,0);
      int MOD = 1e9 +7;
      f[0] = 1;
      f[1] = 1;
      f[2] = 2;
      p[2] = 2;

      for (int i = 3; i <= n; i++) {
        f[i] = (1LL * f[i - 1] + f[i - 2] + p[i - 1]) % MOD;
        p[i] = (1LL * p[i - 1] + 1LL * f[i - 2] * 2) % MOD;
      }
      
      return f[n]; 
    }    
};

/*
這題要把狀態分兩種
1. 甜到i格有填滿
2. 甜到i格沒填滿
f(k) represents the number of ways to fully cover a board 
p(k) represents the number of ways to partially cover a board of width k
*/
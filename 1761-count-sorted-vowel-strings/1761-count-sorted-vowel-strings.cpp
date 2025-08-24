class Solution {
public:
    int countVowelStrings(int n) {
      return comb(n+4,4);
    }
private: 
    long long comb(int m, int n) {
      if (n > m) return 0;
      long long res = 1;
      if (n > m - n) n = m - n;
      for (int i = 0; i < n; i++) {
        res *= (m-i);
        res /= (i+1);
      }
      return res;
    }
};

/*
7
XXXXX

*/
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      int startVal = 0;
      int res = INT_MAX;

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (mat[i][j] == 1) {
            startVal |= (1 << (i*n + j));
          }
        }
      }

      for (int i = 0; i < (1 << (m*n)); i++) {
        int flipVal = 0;
        for (int j = 0,check = 1; j < m*n; j++,check <<= 1) {
          if(i & check) {
            flipVal ^= check;
            if (j%n != 0) {
              flipVal ^= (check >> 1);
            }
            if (j%n != n-1) {
              flipVal ^= (check << 1);
            }
            if (j/n > 0) {
               flipVal ^= (check >> n);
            }
            if (j/n < m-1) {
               flipVal ^= (check << n);
            }
          }
        }
        if ((flipVal ^ startVal) == 0) {
          res = min(res, __builtin_popcount(i));
        }
      }
      return res == INT_MAX ? -1 : res;
    }
};

/*
  same index flip twice  == no flip
  each index have one condition is flip or no flip
  m*n index  2^(m*n) possiblility

 


  0001   0010  0110
  0111   1011  
*/
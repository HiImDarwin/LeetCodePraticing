class Solution {
public:
    int triangularSum(vector<int>& nums) {
      int N = nums.size();
      long long comb[1001][1001];
      for (int i = 0; i <= N; i++) {
        comb[i][i] = comb[i][0] = 1;
        if (i == 0) continue;
        for (int j = 1; j < i; j++) {
          comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
          comb[i][j] %= 10;
        }
      }
      long long res = 0;
      for (int i = 0; i < N; i++) {
        res += (1LL * nums[i] * comb[N-1][i]) % 10;
      }
      return res % 10;
    }
    
    // int combine(int m, int n) {
    //   static vector<int> Table = [&]() -> vector<int> {
    //     vector<int> tmp(m+1);
    //     int val = 1;
    //     for (int i = 0; i <= m/2; i++) {
    //       if (i == 0) {
    //         tmp[i] = tmp[m-i] = val;
    //         continue;
    //       }
    //       val *= (m - i + 1);
    //       val /= i;
    //       tmp[i] = tmp[m-i] = val;
    //     }
    //     return tmp;
    //   }();
    //   return Table[n];
    // }
};


/*
pascal triangel
1
11
121
1331
14641






1+2+2+2+3+3+3+4
2 3 3 3 4 4 4 5

1 2 2 2 2 3 3 3 3 3 3 4 4 4 4 5 
*/
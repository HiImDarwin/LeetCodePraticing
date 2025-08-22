#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
      int m = grid.size();
      int n = grid[0].size();
      std::vector<int> tmp;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          tmp.push_back(grid[i][j]);
        }
      }
      std::sort(tmp.begin(), tmp.end());
      int midian = tmp[m*n/2];
      int res = 0;
      for (int& num :tmp)  {
        if (abs(num - midian)%x != 0) {
          return -1;
        }
        res += abs(num - midian)/x;
      }
      return res;
    }
};
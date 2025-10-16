class Solution {
  int m, n;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
      m = mat.size();
      n = mat[0].size();
      vector<vector<int>> pre(m + 1,vector<int>(n + 1, 0));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          pre[i + 1][j + 1] = mat[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
        }
      }

      int left = 0, right = min(m, n);
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (check( mid, threshold, mat, pre)) {
          left = mid;
        } else { 
          right = mid - 1;
        }
      }
      return left;
    }

    bool check(int len, int threshold, vector<vector<int>>& mat,
               vector<vector<int>>& pre) {
      for (int i = 0; i + len <= m; i++) {
        for (int j = 0; j + len <= n; j++) {
          int sum = pre[i + len][j + len] - pre[i][j + len] - pre[i + len][j] + pre[i][j];
          if (sum <= threshold) {
            return true;
          }
        }
      }
      return false;
    }
};

/*
dp


binary search


*/
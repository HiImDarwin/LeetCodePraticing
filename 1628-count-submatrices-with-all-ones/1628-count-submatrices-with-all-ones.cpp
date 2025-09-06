class Solution {
public:
  //   int numSubmat(vector<vector<int>>& mat) {
  //     int m = mat.size();
  //     int n = mat[0].size();
  //     for(int i = 1; i < m; i++) {
  //       for (int j = 0; j < n; j++) {
  //         if (mat[i][j] == 1) {
  //           mat[i][j] += mat[i - 1][j];
  //         }
  //       }
  //     }
  //     int res = 0;
  //     for (int i = 0; i < m; i++) {
  //       res += countSquare_(mat[i]);
  //     }

  //     return res;
  //   }
  // private:
  //   int countSquare_(vector<int>& mat) {
  //       stack<int> st;
  //       int n = mat.size();
  //       int count = 0;
  //       for (int i = 0; i < n; i++) {
  //         while (!st.empty() && mat[i] <= mat[st.top()]) {
  //           int idx = st.top();
  //           st.pop();
  //           int width = st.empty() ? i : (i - 1) - st.top();
  //           count += width * mat[idx];
  //         }
  //         st.push(i);
  //       }
  //       while(!st.empty()) {
  //         int idx = st.top();
  //         st.pop();
  //         int width = st.empty() ? n : (n - 1) - st.top();
  //         count += width * mat[idx];
  //       }
  //       return count;
  //     }

    int numSubmat(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      int res = 0;
      vector<int> heights(n, 0);
      for (const auto& row : mat) {
        for (int i = 0; i < n; ++i) {
          heights[i] = (row[i] == 0) ? 0 : heights[i] + 1;
        }
        stack<vector<int>> st;
        st.push({-1, 0, -1});
        for (int i = 0; i < n; ++i) {
          int h = heights[i];
          while (st.top()[2] >= h) {
            st.pop();
          }
          auto& top = st.top();
          int j = top[0];
          int prev = top[1];
          int cur = prev + (i - j) * h;
          st.push({i, cur, h});
          res += cur;
        }
      }
      return res;
    }
};



/*
1
11
count all the square in matrix
1. continuous height prefix Sum for each 1
2. left smaller index right smaller index
  left <
  right <=

*/
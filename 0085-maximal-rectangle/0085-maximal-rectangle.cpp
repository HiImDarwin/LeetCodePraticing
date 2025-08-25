class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      int res = 0;
      vector<vector<int>> height(m,vector<int>(n,0));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][j] == '0') continue;
          height[i][j] =  i == 0 ? 1 : height[i-1][j] + 1;
        }
        res = max(res , maxArea(height[i]));
      }
      return res;   
    }

    int maxArea(const vector<int>& heights) {
      vector<int> stack = {-1};
      int maxarea = 0;
      for (int i = 0; i < heights.size(); i++) {
        while (stack.back()!= -1 && heights[stack.back()] >= heights[i]) {
          int height = heights[stack.back()];
          stack.pop_back();
          maxarea = max(maxarea, height * (i - stack.back() - 1));
        }
        stack.push_back(i);
      }
      while (stack.back() != -1) {
        int height = heights[stack.back()];
        stack.pop_back();
        maxarea = max(maxarea, height * (static_cast<int>(heights.size()) - stack.back() - 1));
      }
      return maxarea;
    }
};

/*
區間DP
if height[i][j] >= height[i][j-1];



monotonic stack
*/
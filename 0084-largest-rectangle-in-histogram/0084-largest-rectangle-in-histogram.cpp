class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      vector<int> prevSmaller(n), nextSmaller(n);
      stack<int> st1, st2;

      for(int i = 0; i < n; i++) {
        while(!st1.empty() && heights[st1.top()] >= heights[i]) {
          st1.pop();
        }
        if (st1.empty()) {
          prevSmaller[i] = -1;
        } else {
          prevSmaller[i] = st1.top();
        }
        st1.push(i);
      }

      for(int i = n-1; i >= 0; --i) {
        while(!st2.empty() && heights[st2.top()] >= heights[i]) {
          st2.pop();
        }
        if (st2.empty()) {
          nextSmaller[i] = n;
        } else {
          nextSmaller[i] = st2.top();
        }
        st2.push(i);
      }

      int res = 0;
      for (int i = 0; i < n; i++) {
        res = max(res, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
      }

      return res;
    }
};

/*
高受限於最小的bar
左右邊界取決於prevSmaller nextSmaller


*/
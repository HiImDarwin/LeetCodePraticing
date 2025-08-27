class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
      stack<int> st;
      int total = 0;
      for (int i = 0; i < n; i++) {
        while(!st.empty() && height[st.top()] < height[i]) {
          int botHeight = height[st.top()];
          st.pop();
          if (st.empty()) {
            break;
          }
          int topHeight = min(height[i], height[st.top()]);
          total += (i - st.top() - 1) * (topHeight - botHeight);
        }
        st.push(i);
      }
      return total;
    }
};

/*

leftlarger rightlarger
decreasing monotonic stack

*/ 
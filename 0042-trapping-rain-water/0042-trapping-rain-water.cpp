class Solution {
public:
    int trap(vector<int>& height) {
      stack<int> st;
      int res = 0;
      for (int i = 0; i < height.size(); ++i) {
        while (!st.empty() && height[st.top()] < height[i]) {
          int idx = st.top();
          st.pop();
          if (st.empty()) break;
          int dist = i - st.top() - 1;
          int prev = st.top();
          int h = min(height[prev], height[i]) - height[idx];
          res += dist * h;
        }
        st.push(i);
      }
      return res;
    }
};

/*

leftlarger rightlarger
decreasing monotonic stack

*/ 
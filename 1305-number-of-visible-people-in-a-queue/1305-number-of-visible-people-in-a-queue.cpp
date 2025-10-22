class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
      int n = heights.size();
      stack<int> st;
      vector<int> prepopSum(n + 1, 0);
      vector<int> res;

      for (int i = n - 1; i >= 0; i--) {
        prepopSum[i] = prepopSum[i + 1];
        while (!st.empty() && heights[i] >= heights[st.top()]) {
          st.pop();
          prepopSum[i]++;
        }
        int count = 0;
          if (!st.empty()) {
            count = st.top() - i - prepopSum[i + 1] + prepopSum[st.top()];
          } else {
            count = n - i - 1 - prepopSum[i + 1];
          }
        res.push_back(count);

        st.push(i);
      }

      reverse(res.begin(), res.end());
      return res;
    }
};

/*
  7, 3, 5, 6, 9, 2, 1
  next larger

  maintann a monotonic decreasing deqeue
*/
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
      int n = nums.size();
      int res = 0;
      stack<int> st;
      st.push(-1);
      for (int i = 0 ; i < n; i++) {
        while (st.top() != -1 && nums[st.top()] >= nums[i]) {
          int minVal = nums[st.top()];
          st.pop();
          if (i - st.top() - 1  > threshold/minVal) {
            return (i - st.top() - 1);
          }
        }
        st.push(i);
      }

      while (st.top() != -1) {
        int minVal = nums[st.top()];
        st.pop();
        if (n - st.top() - 1  > threshold/minVal) {
          return (n - st.top() - 1);
        }
      }

      return -1;
    }
};
/*
 1 2 3 4 3 2 1 5 6  6

 
*/
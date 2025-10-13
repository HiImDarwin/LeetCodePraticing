class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMin(n);
    leftMin[0] = INT_MAX;

    for (int i = 1; i < n; i++) {
      leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
    }

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && nums[i] > st.top()) {
        if (leftMin[i] < st.top()) {
          return true;
        }
        st.pop();
      }
      st.push(nums[i]);
    }

    return false;
  }

};

// subsequence not subarray
// LIS 

// find prev larger and prev smaller
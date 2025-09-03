class Solution {
public:
    // int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    //   return count(nums, right) - count(nums, left - 1);
    // }

    // int count(vector<int>& nums , int bound) {
    //   int res = 0, cur = 0;
    //   for (auto& num : nums) {
    //     cur = num <= bound ? cur + 1 : 0;
    //     res += cur;
    //   }
    //   return res;
    // }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
      int n = nums.size();
      vector<int> prevGreaterOrEqual(n,-1);
      vector<int> nextGreater(n, -1);
      stack<int> st;
      st.push(-1);
      for (int i = 0; i < n; i++) {
        while (st.top() != -1 && nums[st.top()] < nums[i]) {
          st.pop();
        }
        prevGreaterOrEqual[i] = st.top();
        st.push(i);
      }
      while(!st.empty()) {
        st.pop();
      }
      st.push(n);
      for (int i = n - 1; i >= 0; --i) {
        while (st.top() != n && nums[st.top()] <= nums[i]) {
          st.pop();
        }
        nextGreater[i] = st.top();
        st.push(i);
      }

      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (left <= nums[i] && nums[i] <= right) {
          res +=  (nextGreater[i] - i) * (i - prevGreaterOrEqual[i]);
        }
      }
      return res;
    }
};

/*
find  maximum in subarrays

deque

[2,1,4,3]

 smaller  < target[] < bigger

smaller in queue
  fix left keep finding target

target[]
  keep going until meet bigeer

meet bigeer
  pop all element in queue

when no [left, right] in queue go until find 
if num > right pop all out
when [left, right] int queue go right until find larger



*/
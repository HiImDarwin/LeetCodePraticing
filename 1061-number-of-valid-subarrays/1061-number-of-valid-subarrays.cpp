class Solution {
public:
    int validSubarrays(vector<int>& nums) {
      nums.push_back(INT_MIN);
      stack<int> st;
      int count = 0;
      for(int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
          count += i - st.top();
          st.pop();
        }
        st.push(i);
      }
      return count;
    }
};


/*
1 2 3 4 9 6 7 8 

a sub array is valid must be strictly increasing



*/
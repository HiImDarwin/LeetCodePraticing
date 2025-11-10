class Solution {
public:
    int minOperations(vector<int>& nums) {
      nums.insert(nums.begin(), -1);
      nums.push_back(-1);
      int n = nums.size();
      vector<int> pre(n), next(n);
      // find prev smaller
      vector<int> st;
      st.push_back(0);

      for (int i = 1; i < n - 1; i++) {
        while (nums[st.back()] >= nums[i]) {
          st.pop_back();
        }
        pre[i] = st.back();
        st.push_back(i);
      }

      // find next smaller
      st.clear();
      st.push_back(n - 1);
      for (int i = n - 2; i > 0; i--) {
        while (nums[st.back()] >= nums[i]) {
          st.pop_back();
        }
        next[i] = st.back();
        st.push_back(i);
      }

      unordered_set<long long> intervels_set;
      int res = 0;
      for (int i = 1; i < n - 1; i++) {
        if (nums[i] == 0) {
          continue;
        }
        long long val = ((long long)pre[i] << 32) + next[i];
        if (intervels_set.find(val) == intervels_set.end()) {
          intervels_set.insert(val);
          res++;
        }
      }
      return res;
    }
};


/*

[1,2,1,2,1,2]
找到最長非 0 的區間最小
比你小的數字會比你更早變0



*/
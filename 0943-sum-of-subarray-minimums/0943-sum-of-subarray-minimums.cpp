class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      int MOD = 1e9 + 7;
      stack<int> st;
      long long res = 0;
      for (int i = 0; i < n; i++) {
        while(!st.empty() && arr[i] <= arr[st.top()]) {
          int idx = st.top();
          st.pop();
          int prevIdx = st.empty() ? -1 : st.top();
          res += (1LL * arr[idx] * (idx - prevIdx) * (i - idx)) % MOD;
          res %= MOD;
        }
        st.push(i);
      }
      while (!st.empty()) {
        int idx = st.top();
        st.pop();
        int prevIdx = st.empty() ? -1 : st.top();
        res += (1LL * arr[idx] * (n - idx) * (idx - prevIdx)) % MOD;
        res %= MOD;
      }

      return res;
    }
};

/*
find pre smaller index /next maller index



*/
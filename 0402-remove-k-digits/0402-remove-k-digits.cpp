class Solution {
public:
    string removeKdigits(string num, int k) {
      if(k == num.length()) return "0";
      int n = num.length();
      stack<char> st;
      for(int i = 0; i< num.length(); i++) {
        while(!st.empty() && num[i] < st.top() && st.size() + n - i > n - k) {
          st.pop();
        }
        if(st.size() < n-k) {
            st.push(num[i]);
        }
      }
      string res;
      while(!st.empty()) {
        res += st.top();
        st.pop();
      }
      while(res.length() > 1 && res.back() == '0') {
        res.pop_back();
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stack<int> st;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
          st.push(i);
        } else if (s[i] == ')' && st.empty()) {
          s[i] = '#';
        } else if (s[i] == ')' && !st.empty()) {
          st.pop();
        }
      }
      while (!st.empty()) {
        int idx = st.top();
        st.pop();
        s[idx] = '#';
      }
      string res;
      for (int i = 0; i < s.length();i++) {
        if (s[i] == '#') continue;
        res += s[i];
      }
      return res;
    }
};


/*

1. used stack 

*/
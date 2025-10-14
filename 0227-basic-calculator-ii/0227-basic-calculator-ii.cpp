class Solution {
public:
    int calculate(string s) {
      stack<long long> st;
      stack<char> oprators;
      int sign = 1;
      int num = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
          continue;
        } else if (isdigit(s[i])) {
          num *= 10;
          num += s[i] - '0';
        } else {
          if (oprators.empty()) {
            st.push(sign * num);
          } else {
            long long prevNum = st.top();
            st.pop();
            if (oprators.top() == '*') {
              st.push(prevNum * num);
            } else if (oprators.top() == '/') {
              st.push(prevNum / num);
            }
            oprators.pop();
          }
          num = 0;
          sign = 1;
          if (s[i] == '-') {
            sign = -1;
          } else if (s[i] == '*' || s[i] == '/') {
            oprators.push(s[i]);
          }
        }
      }
      if (oprators.empty()) {
        st.push(sign * num);
      } else {
        long long prevNum = st.top();
        st.pop();
        if (oprators.top() == '*') {
          st.push(prevNum * num);
        } else if (oprators.top() == '/') {
          st.push(prevNum / num);
        }
        oprators.pop();
      }
      
      long long sum = 0;
      while (!st.empty()) {
        sum += st.top();
        st.pop();
      }
      return sum;
    }
};

/*

separate the num and operator
ss

we got + - * / 
precedance for opertor 

1. how to deal with space
2. how to sepatrate



*/
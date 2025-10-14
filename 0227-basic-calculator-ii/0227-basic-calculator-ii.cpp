class Solution {
public:
    int calculate(string s) {
      stack<long long> st;
      char op = '+';
      int num = 0;
      for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
          num *= 10;
          num += s[i] - '0';
        } 
        
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.length() - 1) {
          if (op == '+') {
            st.push(num);
          } else if (op == '-') {
            st.push(-num);
          } else if (op == '*') {
            long long prev = st.top();
            st.pop();
            st.push(prev * num);
          } else if (op == '/') {
            long long prev = st.top();
            st.pop();
            st.push(prev / num);
          }

          if (!isdigit(s[i])) {
            op = s[i];
          }
          num = 0;
        }     
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
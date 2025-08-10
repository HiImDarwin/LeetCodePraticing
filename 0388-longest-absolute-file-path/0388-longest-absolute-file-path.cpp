class Solution {
public:
    int lengthLongestPath(string input) {
      int n =input.length();
      stack<int> st;
      int pathLength = 0;
      int res = 0;
      int currentDepth = 0;
      int curr = 0;
      int prev = 0;
      while(curr < n) {
        if(input[curr] == '\n') {
          int count = 0;
          curr ++;
          while (input[curr] == '\t') {
            count++;
            curr++;
          }
          while (count < currentDepth) {
            pathLength -= st.top();
            st.pop();
            currentDepth--;
          }
        }
        prev = curr;
        bool isFile = false;
        while (curr < n && input[curr] != '\n') {
          if (input[curr] == '.') {
            isFile = true;
          }
          curr++;
        }
        if (isFile) {
          res = max(res, pathLength + curr - prev);
        } else {
          pathLength += curr - prev + 1; // 1 for the folder back slash
          st.push(curr - prev + 1);
          currentDepth++;
        }
      }

      return res;
    }
};


/*
check depth

check name
  dir
  file
*/
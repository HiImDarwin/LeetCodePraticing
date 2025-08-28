class Solution {
public:
    int maximumSwap(int num) {
      string s = to_string(num);
      int n = s.size();
      stack<int> nextLargest;
      nextLargest.push(n-1);
      for (int i = n - 2; i >= 0; --i) {
        if (s[i] >= s[nextLargest.top()]) {
          nextLargest.push(i);
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i] == s[nextLargest.top()]) {
          nextLargest.pop();
        } else {
          int idx = nextLargest.top();
          nextLargest.pop();
          while (!nextLargest.empty() && s[nextLargest.top()] == s[idx]) {
            idx = nextLargest.top();
            nextLargest.pop();
          }
          swap(s[i],s[idx]);
          break;
        }
      }
      return stoi(s);
    }
};



/*
找出下一個最大值

*/
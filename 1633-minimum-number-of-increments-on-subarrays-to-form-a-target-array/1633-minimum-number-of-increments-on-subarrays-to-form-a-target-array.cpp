class Solution {
public:
    int minNumberOperations(vector<int>& target) {
      stack<int> st;
      target.push_back(0);
      st.push(0);

      int res = 0;
      for (int i = 0; i < target.size(); i++) {
        while (!st.empty() && target[i] < st.top()) {
          int val = st.top();
          st.pop();
          int dif = max(target[i], st.top());
          res += (val - dif);
        }
        if (target[i] == st.top()) {
          continue;
        }
        st.push(target[i]);
      }
      
      return res;
    }
};


/*
find left smaller and right smaller
add num - max(leftsm, rightsm) 
monotonic stack + disjoint set


monotonic stack
num < stack.top()

*/
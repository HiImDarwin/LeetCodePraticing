class Solution {
public:
    string smallestSubsequence(string s) {
      stack<char> st;
      set<char> appear;
      vector<int> lastSaw(256,0);
      for(int i = 0; i < s.length(); ++i) {
        lastSaw[s[i]] = i;
      }
      for(int i = 0; i < s.length(); i++) { 
        if(appear.find(s[i]) != appear.end())
          continue;

        while(!st.empty() && st.top() > s[i] && lastSaw[st.top()] > i) {
          appear.erase(st.top());
          st.pop();
        }
        st.push(s[i]);
        appear.insert(s[i]);
      }
      string res;
      while(!st.empty()) {
        res += st.top(); st.pop();
      }
      reverse(res.begin(), res.end());
      return res;
    }
};

/*
if char didn't appear before  must pick
if left side appear smaller char , but it appear before
 must pick
if left side appear bigger char and appear before  don't pick

*/
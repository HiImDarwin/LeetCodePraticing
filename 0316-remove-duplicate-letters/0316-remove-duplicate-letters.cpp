class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int> last(26,0);
      vector<bool> appear(26,false);
      stack<char> st;

      for(int i = 0; i < s.length(); ++i) {
        last[s[i]-'a'] = i;
      }

      for(int i = 0; i < s.length(); ++i) {
        if(appear[s[i]-'a']) {
          continue;
        }
        while(!st.empty() && s[i] < st.top() && last[st.top()-'a'] > i) {
          appear[st.top()-'a'] = false;
          st.pop();
        }
        st.push(s[i]);
        appear[s[i]-'a'] = true;
      }

      string res;
      while(!st.empty()) {
        res += st.top();
        st.pop();
      }
      reverse(res.begin(),res.end());
      return res;
    }
};

/* 

 
 abcccdsabd
 

*/
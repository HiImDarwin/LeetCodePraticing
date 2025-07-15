class Solution {
public:
    // string removeDuplicates(string s, int k) {
    //   stack<pair<char,int>> st;
    //   int left = 0, right = 0;
    //   while(right < s.length()) {
    //     int charCount = 1;
    //     if(!st.empty() && st.top().first == s[left]) {
    //       charCount += st.top().second;
    //       st.pop();
    //     }
    //     while(right+1 < s.length() && s[right] == s[right+1]) {
    //       right++;
    //       charCount++;
    //     }
    //     if((charCount)%k != 0) {
    //       st.push({s[left],charCount%k});
    //     }
    //     right++;
    //     left = right;
    //   }
    //   string res;
    //   while(!st.empty()) {
    //     res += string(st.top().second,st.top().first);
    //     st.pop();
    //   }
    //   reverse(res.begin(),res.end());
    //   return res;        
    // }
    string removeDuplicates(string s, int k) {
      int i = 0;
      int j = 0;
      vector<int>count(s.size());
      while(j < s.size()) {
        s[i] = s[j];
        count[i] = 1;
        if(i>0 && s[i-1] == s[i]) {
          count[i] += count[i-1];
        }
        if(count[i] == k) {
          i = i-k;
        }
        i++;
        j++;
      }
      return s.substr(0,i);
    
    }
};


/*
naive way
  while() {
    index = 0
    string  = substr() + substr();
  }
  
two stack 
  i dont think it will be faster

naive way + sliding window

stack + sliding window
  case 
  deeedbbcccbdaa


*/
class Solution {
public:
    string minWindow(string s, string t) {
      int m = s.length();
      unordered_map<char,int> table;
      for(char c: t) {
        table[c]++;
      }
      int start = 0, len = INT_MAX, count = 0;
      unordered_map<char,int> record;
      for(int r = 0, l = 0; r < m; r++) {
        if(table.count(s[r])) {
          record[s[r]]++;
          if(record[s[r]] == table[s[r]]) count++;
        }
        
        if(count == table.size()) {
          while(l <= r && count == table.size()) {
            if(r-l+1 < len) {
              start = l;
              len = r-l+1;
            }
            if(table.count(s[l])) {
              record[s[l]]--;
              if(record[s[l]] < table[s[l]]) 
                count--;
            }
            l++;
          }
        }
      }
      return len == INT_MAX ? "" : s.substr(start, len);
    }
};

/*
s m
t n 

a minimum window that t is included in s (duplicate?)

1. for a brute way fixed the window size and go for n-window run  
not find and increase the window size.

2. use character num in window. t got 7 char
so i go from 7 ~ 26 char in window  O(26N) 

3. just slide the window when the need charactor in window 
and the minmize the window from left


*/
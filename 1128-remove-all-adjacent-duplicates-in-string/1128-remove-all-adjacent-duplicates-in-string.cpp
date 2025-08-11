class Solution {
public:
    string removeDuplicates(string s) {
      int i = 0, j = 0;

      while (j < s.length()) {
        if (i == 0 || s[j] != s[i-1]) {
          s[i] = s[j];
          i++;
        } else if ( s[j] == s[i-1]) {
          i--;
        }
        j++;
      }
      return s.substr(0,i);
    }
};


/*
for adjency remove 
compare with stack top and if the element equeal to stack top we drop the element

we can use stack
Time complexity O(n) 
Space complexity O(n) 

use two pointer
Time complexity O(n) 
Space complexity O(1) 



*/
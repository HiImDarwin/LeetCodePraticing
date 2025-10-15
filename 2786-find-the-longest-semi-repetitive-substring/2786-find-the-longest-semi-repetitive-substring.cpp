class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
      if (s.length() == 1) {
        return 1;
      }
      int left = 0, right = 1;
      bool foundOne = false;
      int res = 0;
      while (right < s.length()) {
        if (s[right] == s[right - 1]) {
          if (foundOne) {
            left++;
            while(left > 0 && s[left] != s[left - 1]) {
              left++;
            }
          } else {
            foundOne = true;
          }
        }
        res = max(res, right - left + 1);
        right++;
      }

      return res;
    }
};

/*
find duplicate for right
s[right] == s[right - 1];

*/
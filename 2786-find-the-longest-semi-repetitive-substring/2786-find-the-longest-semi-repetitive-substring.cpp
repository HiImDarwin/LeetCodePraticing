class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
      if (s.length() == 1) {
        return 1;
      }
      int left = 0, right = 1;
      int last_pos = 0;
      bool found_one = false;
      int res = 0;
      while (right < s.length()) {
        if (s[right] == s[right - 1]) {
          left = last_pos;
          last_pos = right;
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
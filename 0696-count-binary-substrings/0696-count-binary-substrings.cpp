class Solution {
public:
    int countBinarySubstrings(string s) {
      int prevLength = 0, currLength = 0;
      int res = 0;

      for (int i = 0; i < s.length(); i++) {
        if (i > 0 && s[i] != s[i - 1]) {
          prevLength = currLength;
          currLength = 0;
        }
        currLength++;
        if (prevLength >= currLength) {
          res++;
        }
      }

      return res;
    }
};
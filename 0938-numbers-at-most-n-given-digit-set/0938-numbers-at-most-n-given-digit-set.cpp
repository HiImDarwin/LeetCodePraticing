class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      string s = to_string(n);
      int len = s.length();
      
      int m = digits.size();
      int res = 0;
      for (int i = 1; i < len; i++) {
        res += pow(m,i);
      }
      for (int i = 0; i < len; i++) {
        bool foundEqual = false;
        for (auto digit : digits) {
          if (digit[0] < s[i]) {
            res += pow(m, len - i - 1);
          } else if (digit[0] == s[i]) {
            foundEqual = true;
            break;
          }
        }
        if (!foundEqual) return res;
      }
      return res + 1;
    }
};



/*
[1, 2, 3, 4]
dfs
*/
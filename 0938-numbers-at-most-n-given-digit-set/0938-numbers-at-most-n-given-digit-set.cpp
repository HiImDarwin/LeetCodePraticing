class Solution {
  int target;
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
        bool prefix_equal = false;
        for (auto &d : digits) {
            if (d[0] < s[i]) {
                res += pow(m, len - i - 1); // this digit smaller → rest free
            } else if (d[0] == s[i]) {
                prefix_equal = true; // continue
            }
        }
        if (!prefix_equal) return res; // can't continue matching n
      }
      return res + 1;
    }
};



/*
[1, 2, 3, 4]
dfs
*/
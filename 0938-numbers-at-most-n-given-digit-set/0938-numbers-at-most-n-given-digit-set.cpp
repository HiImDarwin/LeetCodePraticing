class Solution {
  int len;
  string s;
  int res;
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      s = to_string(n);
      len = s.length();
      
      int m = digits.size();
      res = 0;
      for (int i = 1; i < len; i++) {
        res += pow(m,i);
      }
      DFS(0,digits);
      return res;
    }

    void DFS(int pos, vector<string>& digits) {
      if (pos == len) {
        res += 1;
        return;
      }

      for (string& num : digits) {
        if (num[0] < s[pos]) {
          res += pow(digits.size(), len - pos - 1);
        } else if (num[0] == s[pos]) {
          DFS(pos+1, digits);
        }
      }
    }
};



/*
[1, 2, 3, 4]
dfs
*/
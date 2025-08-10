class Solution {
public:
    string convert(string s, int numRows) {
      int n = s.length();
      if (numRows == 1) return s;
      int jumpRange = numRows*2-2;
      int section = 0;
      string res;
      for (int i = 0; i < numRows; i++) {
        int idx = i;
        int nextJump = jumpRange - i*2;
        if (nextJump == 0) {
            nextJump = jumpRange;
        }
        while (idx < n) {
          res += s[idx];
          idx += nextJump;
          nextJump = jumpRange - nextJump;
          if (nextJump == 0) {
            nextJump = jumpRange;
          }
        }
      }
      return res;
    }
};


/*
row = i%row
for rwo = 0  start go down till  row = numRow-1
for row = numRows -1 start up right till row  = 0 



*/
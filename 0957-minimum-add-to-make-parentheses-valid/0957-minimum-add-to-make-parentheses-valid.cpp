class Solution {
public:
    int minAddToMakeValid(string s) {
      int count = 0;
      int res = 0;
      for(auto& c : s) {
        if (c == '(') {
          count++;
        } else if (c == ')') {
          if (count == 0) {
            res++;
          } else {
            count--;
          }
        }
      }
      return res + count;

    }
};
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
      int n = statements.size();
      int res = 0;
      for (int i = 1; i < (1 << n); i++) { //combination
        bool valid = true;
        for (int j = 0, check = 1; j < n; j++, check <<= 1) { // check bit
          if (i & check) {
            for (int k = 0; k < n; k++){
              // true people said it's good but not in group
              if (statements[j][k] == 1 && (i & (1 << k)) == 0) {
                valid = false;
                break;
              }
              // true people said it's bad but in group
              if (statements[j][k] == 0 && (i & (1 << k))) {
                valid = false;
                break;
              }
            }
          }
          if (!valid) {
            break;
          }
        }
        if (!valid) continue;
        res = max(res,  __builtin_popcount(i));
      }
      return res;
    }  
};

/*
if 2 people statement is different > one of them are bad
if 2 people statement is same
 all possible

1. good people statement must be consistent
    good people in group
    bad people not in group

Ghosper's 

*/
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
      vector<int> count(5);
      int done = 0;
      int res = 0;
      for (const char &c : croakOfFrogs) {
        int idx = charToIndex.count(c) ? charToIndex[c] : 5;
        if(idx == 5) return -1;
        if(idx != 0 && count[idx-1] <= count[idx]) return -1;
        count[idx]++;
        if(idx == 0) {
          res = max(res, count[0] - done);
        }
        if(idx == 4) {
          done++;
        }
      }
      for(int i = 1; i < 5; i++) {
        if (count[i] != count[0]) return -1;
      }

      return res;
    }
    unordered_map<char, int> charToIndex = {
        {'c', 0},
        {'r', 1},
        {'o', 2},
        {'a', 3},
        {'k', 4}
    };
};
/*

"croakcroak"


*/
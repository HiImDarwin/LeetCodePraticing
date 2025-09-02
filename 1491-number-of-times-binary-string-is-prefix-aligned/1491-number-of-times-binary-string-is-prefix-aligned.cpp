class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
      int maxFlip = 0;
      int res = 0;
      for (int i = 0; i < flips.size(); ++i) {
        maxFlip = max(maxFlip,flips[i]);
        if (i+1 == maxFlip) {
          res++;
        }
      }
      return res;
    }
};
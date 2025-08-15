class Solution {
public:
    int maxLength(vector<string>& arr) {
      int n = arr.size();
      vector<int> bitmask;
      for (int i = 0; i< arr.size(); ++i) {
        int mask = 0;
        bool skip = false;
        for (int j = 0; j < arr[i].length(); j++) {
          int idx = (1 << (arr[i][j] - 'a'));
          if (mask & idx) {
            skip = true;
            break;
          }
          mask |= idx;
        }
        if (skip) continue;
        bitmask.push_back(mask);
      }
      int res = 0;
      dfs(0, 0, bitmask, res);
      return res;
    }

    void dfs(int idx,int mask, vector<int>& bitmask,int& res) {
      if (idx == bitmask.size()) {
        res = max(res, __builtin_popcount(mask));
        return;
      }
      if (mask & bitmask[idx]) {
        res = max(res, __builtin_popcount(mask));
      } else {
        dfs(idx+1, mask | bitmask[idx], bitmask, res);
      }
      dfs(idx+1, mask, bitmask, res);
    }
};


/*

how to make caparasion less

*/
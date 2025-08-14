class Solution {
public:
    int maxProduct(vector<string>& words) {
      int n = words.size();
      unordered_map<int,int> mask;
      for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j = 0; j < words[i].length(); j++) {
          tmp |= (1 << (words[i][j] - 'a'));
        }
        if (mask.find(tmp) != mask.end()) {
          mask[tmp] = max(mask[tmp], (int)words[i].length());
        } else {
          mask[tmp] = words[i].length();
        }
      }
      int res = 0;
      for (auto [key1, len1] : mask) {
        for (auto [key2, len2] : mask) {
          if ((key1 & key2) == 0) {
            res = max(res, len1 * len2);
          }
        }
      }
      return res;
    }
};
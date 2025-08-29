class Solution {
public:
    int numSplits(string s) {
      int n = s.length();
      vector<int> distinctCount(n,0);
      
      unordered_set<char> charPool;
      for (int i = 0; i < n; i++) {
        charPool.insert(s[i]);
        distinctCount[i] = charPool.size();
      }

      charPool.clear();
      int res = 0;
      for (int i = n - 1; i > 0; --i) {
        charPool.insert(s[i]);
        if (distinctCount[i - 1] == charPool.size()) {
          res++;
        }
      }
      return res;
    }
};
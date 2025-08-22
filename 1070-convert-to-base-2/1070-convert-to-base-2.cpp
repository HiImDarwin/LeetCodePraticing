class Solution {
public:
    string baseNeg2(int n) {
      if (n == 0) return "0";
      vector<int> remain;
      while (n != 1) {
        int q = n/(-2);
        int r = n%(-2);
        if (r < 0) {
          r += abs(-2);
          q += 1;
        }
        remain.push_back(r);
        n = q;
      }
      remain.push_back(n);
      string res;
      for (int i = remain.size() - 1; i >= 0; --i) {
        res += '0' + remain[i];
      }
      return res;
    }
};
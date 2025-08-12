class Solution {
public:
    int countSubstrings(string s) {
        string t = "#";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
          t += s[i];
          t += '#';
        }
        int m = t.length();
        int maxRight = -1;
        int maxCenter = -1;
        vector<int> radius(m);
        for (int i = 0; i < m; i++) {
          int r;
          if (i < maxRight) { // have mirror  palindrone
            int j = maxCenter * 2 - i;
            r = min(radius[j], maxRight - i);
            while (i - r >= 0 && i + r < m && t[i - r] == t[i + r]) {
              r++;
            }
          } else { // start with 0
            r = 0;
            while (i - r >= 0 && i + r < m && t[i - r] == t[i + r]) {
              r++;
            }
          }
          // find maxRight
          radius[i] = r - 1;
          if (i + radius[i] > maxRight) {
            maxRight = i + radius[i];
            maxCenter = i;
          }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
          res += radius[i]/2;
        }
        res += n;
        return res;
    }
};




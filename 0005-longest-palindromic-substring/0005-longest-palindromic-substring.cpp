class Solution {
public:
  string longestPalindrome(string s) {
    string t = "^";

    for (char &c : s) {
      t += '#';
      t += c;
    }
    t += "#$";

    int n = t.length();
    int center = 1,right = 1;
    vector<int> P(n,0);

    for (int i = 2; i < n - 1; i++) {
      int mirr = center * 2 - i;
      if (i < right) {
        P[i] = min(P[mirr], right - i);
      }
      while ((i + P[i] + 1 < n) && (i - P[i] - 1 >= 0) &&
          t[i + P[i] + 1] == t[i - P[i] - 1]) {
        P[i]++;
      }
      if (i + P[i] > right) {
        center = i;
        right = i + P[i];
      }
    }
    int idx = 0;
    int len = 0;
    for (int j = 1; j < n - 1; j++) {
      if (P[j] > len) {
        len = P[j];
        idx = j;
      }
    }

    return s.substr((idx-P[idx])/2,len);
  }
};


/*

^#a#b#c#b#a#$
idx = 6
p[idx]= 5
*/
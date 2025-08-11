class Solution 
{
  public: 
    string shortestPalindrome(string s) 
    {
      int m = s.length();
      string r = s;
      reverse(r.begin(), r.end());
      r = s + "#" + r;
      int n = r.length();

      vector<int> lps(n, 0);
      int len = 0;
      for (int i = 1; i < n; ++i) {
        while (len > 0 && r[i] != r[len]) {
          len = lps[len-1];
        }
        if (r[i] == r[len]) {
          len++;
        }
        lps[i] = len;
      }
      string tmp = s.substr(lps[n - 1]);
      reverse(tmp.begin(), tmp.end());
      return tmp + s;

    }
};

/*

OOO | XXXXXX | XXX
只能在最前面加東西
因此你會希望中間這段 回文串 越長越好
find the longest prefix s.t. it is a palinedrone 

  OOO | XXXXXX | XXX
s = (B`)   AA`     B
B`是我們要加的 A`是我們要找出來的 反向 prefix
s` = B A` A
*/
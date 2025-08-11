class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        findLps(s, lps);
        
        return lps[n-1] == 0 ? "" : s.substr(n-lps[n-1]);
    }

    void findLps(const string& s, vector<int>& lps) {
      int n = s.length();
      int len = 0;
      for (int i = 1; i < n; i++) {
        while (len > 0 && s[i] != s[len]) {
          len = lps[len-1];
        }
        if (s[i] == s[len]) {
          len++;
        }
        lps[i] = len;
      }
    }
};

/*
suffix[i]: the maximum length k s.t. s[0:k-1] == s[i-k+1 : i]

後綴數組 suffix[n-1] 就是我們的答案

*/
class Solution {
public:
    //  Using string find way
    //int strStr(string haystack, string needle) {
    //     int strStr(string haystack, string needle) {
    //     size_t res = haystack.find(needle);
    //     if(res == string::npos) return -1;
    //     return res;
    // }

    int strStr(string haystack, string needle) {
      int n = needle.length();
      vector<int> lps(n,0);
      buildlps(needle, lps);
      int i = 0, j = 0; 
      while (i < haystack.length()) {
        if (haystack[i] == needle[j]) {
          i++;
          j++;
          if (j == n) {
            return i-j;
          } 
        } else {
          if (j > 0) {
            j = lps[j-1];
          } else {
            i++;
          }
        }
      }
      return -1;
    }

    void buildlps(const string &s, vector<int>& lps) {
      int n = lps.size();
      int len = 0;
      for (int i = 1; i < n; i++) {
        while(len > 0 && s[i] != s[len]) {
          len = lps[len-1];
        }
        if (s[i] == s[len]) {
          len++;
        }
        lps[i] = len;
      }
    }

};
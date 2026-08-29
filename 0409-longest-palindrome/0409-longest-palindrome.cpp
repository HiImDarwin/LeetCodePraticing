class Solution {
public:
  int longestPalindrome(string s) {
    int oddcount = 0;
    vector<int> asic(128, 0);
    
    for(char &c: s) {
      asic[c]++;
      if (asic[c]%2 == 0) {
        oddcount--;
      } else {
        oddcount++;
      }
    }

    return s.length() - (oddcount > 1 ? (oddcount - 1) : 0);
  }
};
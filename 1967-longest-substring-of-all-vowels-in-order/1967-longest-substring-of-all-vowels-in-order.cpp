class Solution {
public:
    int longestBeautifulSubstring(string word) {
      int n = word.length();
      word = word[0] + word;
      int len = 0;
      int res = 0;
      int volve = 1;
      for(int i = 1; i <= n ; ++i) {
        if(word[i] < word[i-1]) {
          if(volve == 5) {
            res = max(res, len);
          }
          volve = 1;
          len = 0;
        }
        if(word[i] > word[i-1]) {
          volve++;
        }
        len++; 
      }
      if(volve == 5) {
        res = max(res, len);
      }
      return res;
    }
};

/*




*/
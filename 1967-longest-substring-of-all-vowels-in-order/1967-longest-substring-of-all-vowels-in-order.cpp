class Solution {
public:
    int longestBeautifulSubstring(string word) {
      int n = word.length();
      word = "a" + word;
      int len = 0;
      int res = 0;
      set<char> charater;
      for(int i = 1; i <= n ; ++i) {
        if(word[i] < word[i-1]) {
          if(charater.size() == 5) {
            res = max(res, len);
          }
          charater.clear();
          len = 0;
        } 
        charater.insert(word[i]);
        len++; 
      }
      if(charater.size() == 5) {
        res = max(res, len);
      }
      return res;
    }

};

/*




*/
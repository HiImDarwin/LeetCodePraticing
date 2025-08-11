class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0 , j =0;
        while (i < word.length() && j < abbr.length()) {
          int count = 0;
          while ('0' <= abbr[j] && abbr[j] <= '9') {
            if (count == 0 && abbr[j] == '0') {
              return false;
            }
            count *= 10;
            count += abbr[j] - '0';
            j++;
          }
          i += count;
          if (i > word.length()) {
            return false;
          }
          if (i < word.length() && j < abbr.length() && abbr[j] == word[i]) {
            i++;j++;
          } else if (i < word.length() && j < abbr.length() && abbr[j] != word[i]) {
            return false;
          }
        }

        if (i < word.length() || j < abbr.length()) {
          return false;
        }
        return true;
    }
};
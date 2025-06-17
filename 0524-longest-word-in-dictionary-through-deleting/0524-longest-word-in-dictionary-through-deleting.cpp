class Solution {
  public:
    string findLongestWord(string s, vector<string>& dictionary) {
      int maxLenght = 0;
      string ans;
      for(string &word: dictionary) {
        int sIdx = 0, wIdx = 0;
        string tmp;
        while(sIdx < s.length() && wIdx < word.length()) {
          if(s[sIdx] == word[wIdx]) {
            tmp += s[sIdx];
            sIdx++;
            wIdx++;
          } else {
            sIdx++;
          }
        }
        if(wIdx == word.length()) {
          if(tmp.length() > ans.length()) {
            ans = tmp;
          } else if (tmp.length() == ans.length()) {
            ans = ans < tmp ? ans : tmp;
          }
        }
      }
      return ans;
    }
};
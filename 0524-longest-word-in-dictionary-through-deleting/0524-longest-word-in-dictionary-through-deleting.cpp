class Solution {
  public:
    string findLongestWord(string s, vector<string>& dictionary) {
      string ans="";
      for(string &word: dictionary) {
        int w_idx = 0, s_idx = 0;
        while(w_idx < word.length() && s_idx < s.length()) {
          if(s[s_idx] == word[w_idx]) ++w_idx;
          ++s_idx;
        }
        if( w_idx == word.length() && 
            (word.length()> ans.length() || (word.length() == ans.length() && word < ans)) ) {
          ans = word;
        }
      }
      return ans;
    }
};
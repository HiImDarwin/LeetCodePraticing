class Solution {
  public:
    string findLongestWord(string s, vector<string>& dictionary) {
      int maxLenght = 0;
      string ans;
      for(string &word: dictionary) {
        if(isSubsequence(s,word)) {
          if(word.length() > ans.length() || 
            (word.length() == ans.length() &&  word < ans)) {
            ans = word;
          }
        }
      }
      return ans;
    }
    bool isSubsequence (const string& s, const string& word) {
      int s_index = 0, w_index = 0;
      while(s_index < s.length() && w_index < word.length()) {
        if(s[s_index] == word[w_index]) {
          ++w_index;
        }
        ++s_index;
      }
      return w_index == word.length();
    }
};
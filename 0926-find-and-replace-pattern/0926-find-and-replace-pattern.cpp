class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      unordered_map<char,char> mp;
      string patStyle;
      int charPos = 0;
      for(int i  = 0; i < pattern.length(); ++i) {
        if(mp.find(pattern[i]) == mp.end()) {
          mp[pattern[i]] = 'a'+charPos;
          charPos++;
        }
        int count = 1;
        while(i+1 <pattern.length() && pattern[i] == pattern[i+1]) {
          count++;
          i++;
        }
        patStyle +=  mp[pattern[i]];
        if(count != 1) patStyle += to_string(count);
      }

      vector<string> res;
      for(string word : words) {
        mp.clear();
        string wordStyle;
        charPos = 0;
        for(int i = 0; i < word.length(); ++i) {
          if(mp.find(word[i]) == mp.end()) {
            mp[word[i]] = 'a'+charPos;
            charPos++;
          }
          int count = 1;
          while(i+1 < word.length() && word[i] == word[i+1]) {
            count++;
            i++;
          }
          wordStyle +=  mp[word[i]];
          if(count != 1) wordStyle += to_string(count);
        }
        if (wordStyle == patStyle) res.push_back(word);
      }
      return res;
    }
};



/*
In this question
the letter can change to anything
so we need to decide a transfer style for words and pattern


*/
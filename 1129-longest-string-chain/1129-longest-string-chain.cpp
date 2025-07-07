class Solution {
public:
    int longestStrChain(vector<string>& words) {
      set<string> wordSet(words.begin(), words.end());
      unordered_map<string, int> memo;
      int res = 0;

      for(string & word : words) {
        res = max(res, dfs(word, wordSet, memo));
      }
      return res;    
    }
    int dfs(string word, set<string> &wordSet, unordered_map<string, int> &memo) {
      if(memo.count(word)) return memo[word];

      int maxLen = 1;
      for(int i = 0 ; i < word.length(); ++i) {
        string tmp = word.substr(0,i) + word.substr(i+1);
        if(wordSet.count(tmp)) {
          maxLen = max(maxLen, dfs(tmp, wordSet, memo)+1);
        }
      }
      return memo[word] = maxLen;
    }
};


/*

Lowercase latter

worda insert '*' at anywhere be wordb
lengtha +1 = lengthb
find the longest length of word chain in words


[a,b,cb,ba,bab,babc,babd,]

key
1. the longest word chain may not start from shortest word and stop on longest word
2. the calculation may duplicate

DP top down



DP bot up





Question
1. word length <=16
2. how many element in words
3. is char is uppercase or lower case or both?

*/
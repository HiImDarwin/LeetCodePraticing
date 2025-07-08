class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      unordered_map<string,int> Map;
      unordered_set<string> Set;
      int count = 0;
      for(string &word : words) {
        if (word[0] == word[1]) {
          if (Set.find(word) != Set.end()) {
            count++;
            Set.erase(word);
          } else {
            Set.insert(word);
          }
        } else if (Map[word] > 0) {
          count++;
          Map[word]--;
        } else {
          string tmp = string(1,word[1])+word[0];
          Map[tmp]++;
        }
      }
      return count*4 + (Set.size() > 0 ? 2 : 0); 
    }
};


/*
"caac" "abdcesv" "vse" "d" "dba" 

condition 1: a word can form palindrome by itself
  "aa"
condition 2: a word can make up palindrome with another 1 word
  "ab" "ba" > "abccba"

1. check if itself can be a palindrome
2. check if there exist palindrome pair with it



question:
1. charater is lower or upper case?
2. is word length fixed? yes only 2

*/
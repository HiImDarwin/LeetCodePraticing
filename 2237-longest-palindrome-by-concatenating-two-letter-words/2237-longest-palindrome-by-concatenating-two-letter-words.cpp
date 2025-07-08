class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      unordered_map<string,int> Map;
      int count = 0;
      for(string &word : words) {
        if (word[0] == word[1]) {
          Map[word]++;
        } else {
          string rev = word;
          reverse(rev.begin(), rev.end());
          if (Map[rev] > 0) {
              count+=4;
              Map[rev]--;
          } else {
              Map[word]++;
          }
        }
      }
      bool center = false;
      for(auto word : Map) {
        if(word.first[0] == word.first[1]) {
          count += 4*(word.second/2);
          if(!center && word.second%2 == 1) {
            count += 2;
            center = true;
          } 
        }
      }
      return count;
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
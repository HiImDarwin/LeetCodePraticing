class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
      int count = 0;
      unordered_set<string> startSet;
      for (auto& s : startWords) {
        sort(s.begin(), s.end());
        startSet.insert(s);
      }
      int res = 0;
      for (auto& s : targetWords) {
        sort(s.begin(),s.end());
        for (int i = 0 ; i < s.length(); i++) {
          string tmp = s.substr(0,i) + s.substr(i+1);
          if (startSet.find(tmp) != startSet.end()) {
            res++;
            break;
          }
        }
      }
      return res;
    }
};

/*
trie
O(n * m)

only on operation ! so check

DFS in trie O(n * m)
  check letter in target didin't duplicate in path
  the word in startWords can't be same as targetwords


*/
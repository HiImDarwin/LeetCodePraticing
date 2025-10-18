class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string,vector<string>> routeMap;
      int m = beginWord.length();
      for (int i = 0; i < m; i++) {
        for (const string& word : wordList) {
          string tmp = word;
          tmp[i] = '*';
          routeMap[tmp].push_back(word);
        }
      }
      unordered_set<string> visited;
      queue<pair<string,int>> qu;
      qu.push({beginWord,1});
      visited.insert(beginWord);
      while (!qu.empty()) {
        auto [node, numOfWord] = qu.front();
        qu.pop();
        if (node == endWord) {
          return numOfWord;
        }
        for (int i = 0; i < m; i++) {
          int c = node[i];
          node[i] = '*';
          for (auto& nei : routeMap[node]) {
            if (visited.count(nei)) {
              continue;
            }
            qu.push({nei, numOfWord + 1});
            visited.insert(nei);
          }
          node[i] = c;
        }
      }

      return 0;
    }
};


/*
  dfs
  hot dot dog lot log cog
  *ot: hot dot log
  *og: dog log cog
  h*t: hot
  d*t: dot


*/
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    unordered_map<string, vector<int>> link;
    vector<bool> visited(n, false);
    queue<int> qu;

    for (int j = 0; j < n; j++) {
      string word = wordList[j];
      for (int i = 0; i < word.length(); i++) {
        string tmp = word;
        tmp[i] = '*';
        link[tmp].push_back(j);
      }
      if (word == beginWord) {
        qu.push(j);
        visited[j] = true;
      }
    }
    if (qu.empty()) {
      wordList.push_back(beginWord);
      qu.push(n);
    }

    int res = 0;
    while(!qu.empty()) {
      res++;
      int size = qu.size();
      while (size > 0) {
        int idx = qu.front();
        qu.pop();
        size--;
        if (wordList[idx] == endWord) {
          return res;
        } 
        for (int j = 0; j < wordList[idx].length(); j++) {
          string tmp = wordList[idx];
          tmp[j] = '*';
          for (auto &nei : link[tmp]) {
            if (visited[nei] != true) {
              qu.push(nei);
              visited[nei] = true;
            }
          }
        }
      }
    }
    
    return 0;
  }
};


// word is node and the *xx is the link between thoose node


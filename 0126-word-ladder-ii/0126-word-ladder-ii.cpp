class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());
      if (!dict.count(endWord)) return {};

      unordered_map<string, vector<string>> patternMap;
      for(string word : wordList) {
        for(int j = 0; j < wordList[0].length(); ++j) {
          string tmp = word;
          tmp[j] = '*';
          patternMap[tmp].push_back(word);
        }
      }

      unordered_map<string, vector<string>> parents;
      unordered_map<string, int> dist;
      queue<string> q;
      q.push(beginWord);
      dist[beginWord] = 0;

      while(!q.empty()) {
        string word = q.front(); q.pop();
        int curDist = dist[word];
        for (int i = 0; i < word.size(); ++i) {
          string pattern = word;
          pattern[i] = '*';
          for(const string& nei : patternMap[pattern]) {
            if (!dist.count(nei)) {
              dist[nei] = curDist + 1;
              q.push(nei);
            } 
            if (dist[nei] == curDist + 1) {
              parents[nei].push_back(word);
            }
          }
        }
      }

      vector<vector<string>> res;
      vector<string> path;
      function<void(string)> dfs = [&](const string& word) {
        path.push_back(word);
        if(word == beginWord) {
          reverse(path.begin(), path.end());
          res.push_back(path);
          reverse(path.begin(), path.end());
        } else {
          for (const string& par: parents[word]) {
            dfs(par);
          }
        }
        path.pop_back();
      };
      dfs(endWord);
      return res;
    } 
};
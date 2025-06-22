class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string,vector<string>> patternMap;
    bool foundEnd = false;
    for (auto word : wordList) {
      foundEnd |= (word == endWord);
      for(int i = 0; i<word.length(); ++i) {
        string pattern = word;
        pattern[i] = '*';
        patternMap[pattern].push_back(word);
      }
    }
    if(!foundEnd) return 0;

    queue<string> qu;
    qu.push(beginWord);
    unordered_map<string,int> dist;
    dist[beginWord] = 1;
    while(!qu.empty()) {
      string node = qu.front(); qu.pop();
      for(int i = 0; i < node.length(); ++i) {
        string pattern = node;
        pattern[i] = '*';
        for( auto sib : patternMap[pattern]) {
          if(sib == endWord) return  dist[node] + 1;
          if(dist.count(sib)) continue;
          dist[sib] = dist[node] + 1;
          qu.push(sib);
        }
      }
    }
    return  0;
  }
};
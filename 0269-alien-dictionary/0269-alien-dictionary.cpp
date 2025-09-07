class Solution {
public:
    string alienOrder(vector<string>& words) {
      if (words.size() == 0) return "";
      unordered_map<char, int> indegree;
      unordered_map<char, unordered_set<char>> graph;

      for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
          char c = words[i][j];
          indegree[c] = 0;
        }
      }

      for (int i = 0; i < words.size() - 1; i++) {
        string cur = words[i];
        string nex = words[i + 1];
        if (cur.size() > nex.size() && cur.substr(0, nex.size()) == nex) {
          return "";
        }
        for (int j = 0; j < min(cur.size(), nex.size()); j++) {
          if (cur[j] == nex[j]) {
            continue;
          }
          if (graph[cur[j]].find(nex[j]) ==  graph[cur[j]].end()) {
            graph[cur[j]].insert(nex[j]);
            indegree[nex[j]]++;
          }
          break;
        }
      }

      string ans;
      queue<char> q;
      for (auto& e : indegree) {
        if (e.second == 0) {
          q.push(e.first);
        }
      }
      while (!q.empty()) {
        char cur = q.front();
        q.pop();
        ans += cur;

        for (auto& e : graph[cur]) {
          indegree[e]--;
          if (indegree[e] == 0) {
            q.push(e);
          }
        }
      }

      return ans.length() == indegree.size() ? ans : "";  
    }
};
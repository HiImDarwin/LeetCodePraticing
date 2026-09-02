class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> course(numCourses, 0);
    queue<int>qu;
    unordered_map<int, vector<int>> adj;
    for(auto vec : prerequisites) {
      course[vec[1]]++;
      adj[vec[0]].push_back(vec[1]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (course[i] == 0) {
        qu.push(i);
      }
    }
    while(!qu.empty()) {
      int cur = qu.front();
      qu.pop();
      numCourses--;
      if (adj.find(cur) == adj.end()) {
        continue;
      }
      for(auto &nei : adj[cur]) {
        course[nei]--;
        if (course[nei] == 0) {
          qu.push(nei);
        }
      }
    }

    return numCourses == 0 ? true : false;
  }
};
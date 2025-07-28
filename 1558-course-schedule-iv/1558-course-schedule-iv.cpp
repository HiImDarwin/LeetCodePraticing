class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      
      vector<unordered_set<int>> next(numCourses);
      vector<int> inDegree(numCourses,0);
      vector<unordered_set<int>> preSet(numCourses);

      for (auto edge : prerequisites) {
        next[edge[0]].insert(edge[1]);
        inDegree[edge[1]]++;
      }

      queue<int> q;
      for (int i = 0; i < numCourses; ++i) {
        preSet[i].insert(i);
        if(inDegree[i] == 0) {
          q.push(i);
        }
      }

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: next[cur]) {
          for (auto x : preSet[cur]) {
            preSet[next].insert(x);
          }
          inDegree[next]--;
          if (inDegree[next] == 0) {
            q.push(next);
          }
        }
      }
      vector<bool> res;
      for(auto query : queries) {
        res.push_back(preSet[query[1]].find(query[0]) != preSet[query[1]].end());
      }
      return res;
    }
};

/*
topology sort + disjoint set


*/
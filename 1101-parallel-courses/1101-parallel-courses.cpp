class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
      vector<int> indegree(n + 1, 0);
      vector<vector<int>> adj(n + 1);
      for (auto& require : relations) {
        indegree[require[1]]++;
        adj[require[0]].push_back(require[1]);
      }

      queue<int> qu;
      for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
          qu.push(i);
        }
      }

      int semester = 0;
      int courseCount = 0;
      
      while (!qu.empty()) {
        queue<int> newQu;
        int size = qu.size();
        semester++;
        while (!qu.empty()) { 
          int course = qu.front();
          courseCount++;
          qu.pop();
          for (int next : adj[course]) {
            indegree[next]--;
            if (indegree[next] == 0) {
              newQu.push(next);
            }
          }
        }
        qu.swap(newQu);
      }

      return courseCount == n ? semester : -1; 
    }
};
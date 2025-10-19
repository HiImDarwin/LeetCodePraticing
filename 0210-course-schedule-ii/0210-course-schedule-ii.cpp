class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indegree(numCourses);
      vector<vector<int>> adj(numCourses);

      for(auto pre : prerequisites) {
        int a = pre[0];
        int b = pre[1];
        indegree[a]++;
        adj[b].push_back(a);
      }

      queue<int> qu;
      for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
          qu.push(i);
        }
      }
      

      vector<int> courseOrder;

      while (!qu.empty()) {
        queue<int> new_qu;

        while (!qu.empty()) {
          int course = qu.front();
          qu.pop();
          courseOrder.push_back(course);
          for (auto& nei : adj[course]) {
            if (--indegree[nei] == 0) {
              new_qu.push(nei);
            }
          }
        } 
        qu.swap(new_qu);
      }

      return (courseOrder.size() == numCourses) ? courseOrder : vector<int>{};
    }
};
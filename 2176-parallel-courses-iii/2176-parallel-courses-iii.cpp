class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
      vector<int> indegree(n+1,0);
      vector<vector<int>> adj(n+1);
      vector<int> startTime(n+1, INT_MIN);
      
      // build graph
      for (auto& dependency : relations) {
        int prev = dependency[0];
        int next = dependency[1];
        adj[prev].push_back(next);
        indegree[next]++;
      }

      // count path Time
      queue<int> qu;  //course start time 
      for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
          startTime[i] = 0;
          qu.push(i);
        }
      }

      int res = 0;
      while (!qu.empty()) {
        int course = qu.front();
        qu.pop();
        int endTime = startTime[course] + time[course - 1];
        res = max(res, endTime);

        for (auto& nextCourse : adj[course]) {
          startTime[nextCourse] = max(startTime[nextCourse], endTime);
          indegree[nextCourse]--;
          if (indegree[nextCourse] == 0) {
            qu.push(nextCourse);
          }
        }

      }

      return res;
    }
};
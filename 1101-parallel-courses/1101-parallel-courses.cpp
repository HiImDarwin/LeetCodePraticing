class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) 
    {
      unordered_map<int,vector<int>> nextCourses;
      vector<int> inDegree(n+1,0);
      for (auto edge : relations) {
        int prevCourse = edge[0];
        int nextCourse = edge[1];
        inDegree[nextCourse]++;
        nextCourses[prevCourse].push_back(nextCourse);
      }
      queue<pair<int,int>> courseCanTake;
      for(int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
          courseCanTake.push({i,1});
        }
      }
      int count = 0;
      int res = 0;
      while (!courseCanTake.empty()) {
        auto [course, semester] = courseCanTake.front();
        courseCanTake.pop();
        count++;
        res = max(res,semester);
        for(auto nextCourse : nextCourses[course]) {
          inDegree[nextCourse]--;
          if(inDegree[nextCourse] == 0) {
            courseCanTake.push({nextCourse,semester+1});
          }
        }
      }
      
      return count == n ? res : -1;
    }
};

/*
find the longest topology sort path

*/
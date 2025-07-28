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
      queue<int> courseCanTake;
      for(int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
          courseCanTake.push(i);
        }
      }
      int count = 0;
      int res = 0;
      while (!courseCanTake.empty()) {
        int size = courseCanTake.size();
        res++;
        for (int i = 0; i < size; ++i) {
          auto course = courseCanTake.front();
          courseCanTake.pop();
          count++;
          for(auto nextCourse : nextCourses[course]) {
            inDegree[nextCourse]--;
            if(inDegree[nextCourse] == 0) {
              courseCanTake.push(nextCourse);
            }
          }
        }
      }
      
      return count == n ? res : -1;
    }
};

/*
find the longest topology sort path

*/
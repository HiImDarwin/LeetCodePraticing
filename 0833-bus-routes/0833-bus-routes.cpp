class Solution 
{
  public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
      unordered_map<int,vector<int>> stationInfo; // station routes
      for (int i = 0; i < routes.size(); ++i) {
        for (int j = 0; j < routes[i].size(); ++j) {
          stationInfo[routes[i][j]].push_back(i);
        }
      }

      queue<int> qu;
      unordered_set<int> visited;
      unordered_set<int> visitedRoutes;
      int takenNum = 0;
      qu.push(source);
      visited.insert(source);

      while (!qu.empty()) {
        int num = qu.size();
        for (int i = 0; i < num; ++i) {
          int station = qu.front();
          qu.pop();
          if (station == target) {
            return takenNum;
          }

          for(auto route : stationInfo[station]) {
            if(visitedRoutes.find(route) != visitedRoutes.end()) {
              continue;
            }
            for(int station : routes[route]) {
              if(visited.find(station) != visited.end()) {
                continue;
              }
              visited.insert(station);
              qu.push(station);
            }
            visitedRoutes.insert(route);
          }
        }
        takenNum++;  
      }

      return -1;
    }
};
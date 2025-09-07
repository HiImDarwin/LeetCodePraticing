class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      unordered_map<int, vector<int>> xAxis, yAxis;
      for (auto& vec : obstacles) {
        int x = vec[0];
        int y = vec[1];
        xAxis[x].push_back(y);
        yAxis[y].push_back(x);
      }
      for (auto& [key, vec] : xAxis) {
        sort(vec.begin(), vec.end());
      }
      for (auto& [key, vec] : yAxis) {
        sort(vec.begin(), vec.end());
      }
      return startWalk_(commands, xAxis, yAxis);

    }
  private:
    int startWalk_(vector<int>& commands, unordered_map<int, vector<int>> xAxis,
                              unordered_map<int, vector<int>> yAxis) {
      int dir = 0;
      int maxEuclidean = 0;
      int x = 0, y = 0;
      for (auto& cmd : commands) {
        if (cmd < 0) {
          if (cmd == -1) {
            dir = (dir + 1) % 4;
          } else {
            dir = (dir + 3) % 4;
          }
        } else {
          auto [dx, dy] = directions[dir];
          if (dir % 2 == 0) {
            int move = cmd * dy;
            if (dy < 0) {
              auto it = lower_bound(xAxis[x].begin(), xAxis[x].end(), y);
              int nearestObstacle = (it != xAxis[x].begin()) ? *prev(it,1) : INT_MIN;
              y = max(y + move, nearestObstacle + 1);
            } else {
              auto it = upper_bound(xAxis[x].begin(), xAxis[x].end(), y);
              int nearestObstacle = (it != xAxis[x].end()) ? *it : INT_MAX;
              y = min(y + move, nearestObstacle - 1);
            }
          } else {
            int move = cmd * dx;
            if (dx < 0) {
              auto it = lower_bound(yAxis[y].begin(), yAxis[y].end(), x);
              int nearestObstacle = (it != yAxis[y].begin()) ? *prev(it,1) : INT_MIN;
              x = max(x + move, nearestObstacle + 1);
            } else {
              auto it = upper_bound(yAxis[y].begin(), yAxis[y].end(), x);
              int nearestObstacle = (it != yAxis[y].end()) ? *it : INT_MAX;
              x = min(x + move, nearestObstacle - 1);
            }
          }
          maxEuclidean = max(maxEuclidean, x * x + y * y);
        }
      }
      return maxEuclidean;
    }

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};




/*
ceate a obstacles map

1. handle datastrucutr
unordered_map<int, vector<int>>
unordered_map<int, vector<int>>

2. handle command
+ directions
 0 upperbound 
+ directions 
  lowerbound prev

*/


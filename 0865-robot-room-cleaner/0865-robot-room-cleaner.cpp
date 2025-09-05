/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
  

public:
    void cleanRoom(Robot& robot) {
      unordered_set<string> cleanMap;
      dir = 0;
      dfs_(0, 0, robot, cleanMap);
    }
  private:
    void dfs_(int x, int y, Robot& robot, unordered_set<string>& cleanMap) {
      int enterDir = dir;

      string pos = to_string(x) + "#" + to_string(y);
      cleanMap.insert(pos);
      robot.clean();

      for (int i = 0; i < 4; i++) {
        int targetDir = (enterDir + i) % 4;
        while (dir != targetDir) {
          dir = (dir + 1) % 4;
          robot.turnRight();
        }
        
        auto [dx, dy] = directions[dir];
        int nextX = x + dx;
        int nextY = y + dy;
        string nextPos = to_string(nextX) + "#" + to_string(nextY);

        if (cleanMap.find(nextPos) != cleanMap.end() || !robot.move()) {
          continue;
        }
        dfs_(nextX, nextY, robot, cleanMap);
      }
      while (dir != (enterDir+2) % 4) {
        dir = (dir + 1) % 4;
        robot.turnRight();
      }
      robot.move();
    }

    vector<pair<int,int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir;
};

/*
build map


how to know if a place have been clean?
index set

face up    {0,  1}
face down  {0, -1}
face right {1, 0}
face left  {-1, 0}

face up turn right {0, 1} > {1, 0} > {0, -1} > {-1, 0} > {0, 1}
face up turn left  {0, 1} > {0, 0} > {0, -1} > {-1, 0} > {0, 1}
int dir = 0;

turnright dir = (dir + 1) % 4;
trunleft dir = (dir + 3) % 4;
vector<pair<int,int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};



*/
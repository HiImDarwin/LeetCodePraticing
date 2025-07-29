/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution 
{
  int tarX;
  int tarY;
public:
    int findShortestPath(GridMaster &master) 
    {
      vector<vector<int>> visited(201, vector<int>(201,-1));
      vector<vector<int>> cost(201, vector<int>(201,-1));
      visited[100][100] = 1;
      cost[100][100] = 0;
      if(!dfs(visited, cost, 100, 100, master)) return -1;

      vector<vector<int>> shortest(201, vector<int>(201,INT_MAX));
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<>> indexQueue;
      indexQueue.push({0,{100,100}});
      shortest[100][100] = 0;

      while(!indexQueue.empty()) {
        auto cur = indexQueue.top();
        indexQueue.pop();
        int dist = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        if(x == tarX && y == tarY) return dist;

        for(char dir : directions) {
          auto [neiX, neiY] = neiIndex(x,y,dir);

          if(visited[neiX][neiY] == -1) continue;
          if(dist + cost[neiX][neiY] < shortest[neiX][neiY]) {
            shortest[neiX][neiY] = dist + cost[neiX][neiY];
            indexQueue.push({shortest[neiX][neiY],{neiX,neiY}});
          }
        }
      }
      return -1;
    }

    bool dfs(vector<vector<int>> &visited, vector<vector<int>> &costMap, int x, int y, GridMaster &master) {
      visited[x][y] = 1;
      bool found = false;
      if(master.isTarget()) {
        tarX = x;
        tarY = y;
        found = true;
      } 
      
      for(auto &dir : directions) {
        auto [neiX, neiY] = neiIndex(x , y , dir);
        if(visited[neiX][neiY] == 1) continue;
        if(!master.canMove(dir)) continue;

        costMap[neiX][neiY] = master.move(dir);
        found |= dfs(visited, costMap, neiX, neiY, master);
        master.move(oppositeDir(dir));
      }
      return found;
    }

    char oppositeDir(char c) {
      if(c == 'U') return 'D';
      if(c == 'D') return 'U';
      if(c == 'L') return 'R';
      return 'L';
    }

    pair<int, int> neiIndex(int x, int y, char c) {
      if(c == 'U') return {x , y-1};
      if(c == 'D') return {x , y+1};
      if(c == 'L') return {x-1 , y};
      return {x+1 , y};
    }

    vector<char> directions = {'U','D','L','R'};
};

/*
find shortest path to target

don't know the dimension
used 4 2D array for 4 dimension (++ +- -- -+)



*/
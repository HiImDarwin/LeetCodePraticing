class Solution 
{
  private:
    int m;
    int n;
    vector<vector<bool>> visited;
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
      m = maze.size();
      n = maze[0].size();
      visited.resize(m,vector<bool>(n,false));
      return bfs(maze,start[0],start[1],destination[0],destination[1]);
    }
    bool bfs(vector<vector<int>>& maze, int srcX, int srcY, int targetX, int targetY) {
      queue<pair<int,int>> qu;
      qu.push({srcX, srcY});

      while(!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();
        visited[x][y] = true;
        for(auto [dx, dy] : direction) {
          int endX = x;
          int endY = y;
          while(endX < m && endX >=0 && endY < n && endY >= 0 && maze[endX][endY] != 1) {
            endX += dx;
            endY += dy;
          }
          endX -= dx;
          endY -= dy;
          if(visited[endX][endY]) continue;
          if(endX == targetX && endY == targetY) return true;
          qu.push({endX,endY});
        }
      }
      return false;
    }

    vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
};

/*


*/
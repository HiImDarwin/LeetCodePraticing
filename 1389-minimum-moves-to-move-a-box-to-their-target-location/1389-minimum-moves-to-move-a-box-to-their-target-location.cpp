class Solution {

public:
    int minPushBox(vector<vector<char>>& grid) {
      m = grid.size();
      n = grid[0].size();


      int p_x, p_y, b_x, b_y;
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == 'S') {
            p_x = i;
            p_y = j;
            grid[i][j] = '.';
          } else if (grid[i][j] == 'B') {
            b_x = i;
            b_y = j;
            grid[i][j] = '.';
          }
        }
      }
      using State = array<int,4>;
      queue<State> qu;
      qu.push({b_x, b_y, p_x, p_y});
      set<State> visited;
      visited.insert({b_x, b_y, p_x, p_y});
      
      int push = 0;
      while (!qu.empty()) {
        int len = qu.size();
        while (len--) {
          auto [box_x, box_y, per_x, per_y] = qu.front();
          qu.pop();
          if (grid[box_x][box_y] == 'T') {
            return push;
          }
          
          for (int i = 0; i < 4; i++) {
            int nei_x = box_x + directions[i].first;
            int nei_y = box_y + directions[i].second;
            int per_next_x = box_x + directions[(i + 2) % 4].first;
            int per_next_y = box_y + directions[(i + 2) % 4].second;
            State next = {nei_x, nei_y, per_next_x, per_next_y};
            if (nei_x < 0 || nei_x >= m || nei_y < 0 || nei_y >= n || 
                grid[nei_x][nei_y] == '#' || visited.count(next)) {
              continue;
            }
            if (!moveBehindBox(grid, box_x, box_y, per_x, per_y, per_next_x, per_next_y)) {
              continue;
            }
            visited.insert(next);
            qu.push(next);

          }
        }
        push++;
      }
      
      return -1;
    }

  private:
    bool moveBehindBox(vector<vector<char>>& grid,int bx, int by, int px, int py, int tx, int ty) {
      queue<pair<int,int>> qu;
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      visited[px][py] = true;
      qu.push({px, py});
      while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();
        if (x == tx && y == ty) {
          return true;
        }
        for (auto [dx, dy] : directions) {
          int nei_x = x + dx;
          int nei_y = y + dy;
          if (nei_x < 0 || nei_x >= m || nei_y < 0 || nei_y >= n) {
            continue;
          }
          if (grid[nei_x][nei_y] == '#' || (nei_x == bx && nei_y== by) || visited[nei_x][nei_y]) {
            continue;
          }
          visited[nei_x][nei_y] = true;
          qu.push({nei_x, nei_y});
        }
      }

      return false;
    }
    vector<pair<int,int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int m, n;
};


/*
B: box
T: targetPos
S: player
.: free cell
#: wall
only one box 'B' and one target cell 'T' i


step 1 
 S find B
step 2 
  
two function
 1. move behind box

 2. push

*/
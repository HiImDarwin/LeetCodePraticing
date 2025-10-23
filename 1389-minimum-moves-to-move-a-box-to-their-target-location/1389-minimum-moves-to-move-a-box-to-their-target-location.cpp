class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int p_x, p_y, b_x, b_y;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    p_x = i; p_y = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'B') {
                    b_x = i; b_y = j;
                    grid[i][j] = '.';
                }
            }
        }

        using State = array<int,4>;
        queue<State> qu;
        set<State> visited;
        qu.push({b_x, b_y, p_x, p_y});
        visited.insert({b_x, b_y, p_x, p_y});

        int push = 0;
        while (!qu.empty()) {
            int len = qu.size();
            while (len--) {
                auto [bx, by, px, py] = qu.front();
                qu.pop();

                if (grid[bx][by] == 'T') return push;

                for (auto [dx, dy] : directions) {
                    int nbx = bx + dx, nby = by + dy;   // next box position
                    int npx = bx - dx, npy = by - dy;   // player must stand here before push

                    if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || grid[nbx][nby] == '#')
                        continue;

                    State next = {nbx, nby, npx, npy};
                    if (visited.count(next)) continue;

                    if (!moveBehindBox(grid, bx, by, px, py, npx, npy))
                        continue;

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
        qu.push({px, py});
        visited[px][py] = true;
        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            if (x == tx && y == ty) return true;
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] == '#' || (nx == bx && ny == by) || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                qu.push({nx, ny});
            }
        }
        return false;
    }

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
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
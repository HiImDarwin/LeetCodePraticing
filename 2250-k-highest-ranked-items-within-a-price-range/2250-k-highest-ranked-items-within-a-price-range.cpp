class Solution {

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        bfs(start, pricing, grid);
        vector<vector<int>> res;
        while (k > 0 && !pq.empty()) {
          auto itemInfo = pq.top();
          pq.pop();
          res.push_back({itemInfo[2], itemInfo[3]});
          k--;
        }
        return res;
    }

  private:
    void bfs(vector<int>& start,vector<int>& pricing,vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<bool>> visited(m,vector<bool>(n,false));
      queue<pair<pair<int,int>,int>> qu;
      qu.push({{start[0],start[1]},0});
      visited[start[0]][start[1]] = true;
      while (!qu.empty()) {
        auto node = qu.front();
        qu.pop();
        int x = node.first.first;
        int y = node.first.second;
        int dist = node.second;
        if (pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1]) {
          pq.push({dist, grid[x][y], x, y});
        }

        for (auto [dx, dy] : dir) {
          int neiX = x + dx;
          int neiY = y + dy;
          if (neiX < 0 || neiX >= m || neiY < 0 || neiY >= n || 
              grid[neiX][neiY] == 0 || visited[neiX][neiY]) {
            continue;
          }
          qu.push({{neiX,neiY},dist + 1});
          visited[neiX][neiY] = true;
        }
      }
    }

    vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
};


/*
BFS to achieve every item and used priority queue to sort them

*/
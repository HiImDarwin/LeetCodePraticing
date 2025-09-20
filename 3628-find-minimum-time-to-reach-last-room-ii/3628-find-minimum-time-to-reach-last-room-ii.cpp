class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
      int n = moveTime.size();
      int m = moveTime[0].size();
      vector<vector<vector<int>>> memo(n,vector<vector<int>>(m,vector<int>(2,INT_MAX)));
      memo[0][0][0] = 0;
      memo[0][0][1] = 0;
      priority_queue<vector<int>,vector<vector<int>>, greater<>> pq;
      pq.push({0, 0, 0, 0}); // time  node
      while (!pq.empty()) {
        auto vec = pq.top();
        pq.pop();
        int time = vec[0];
        int step = vec[1];
        int x = vec[2];
        int y = vec[3];
        if (x == n - 1 && y == m - 1) {
          return time;
        }
        for (auto& [dx, dy] : directions) {
          int neiX = x + dx;
          int neiY = y + dy;
          if (neiX < 0 || neiX >= n || neiY < 0 || neiY >= m) {
            continue;
          }
          int newTime = max(time, moveTime[neiX][neiY]) + step + 1;
          if (newTime < memo[neiX][neiY][(step + 1) % 2]) {
            memo[neiX][neiY][(step + 1) % 2] = newTime;
            pq.push({newTime, (step + 1) % 2, neiX, neiY});
          } 
        }
      }

      return -1;
    }
  private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

/*
dijkstra
  priority queue 
  memorize

time
step 
node



*/
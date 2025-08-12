class Solution {
  int m,n;
  
public:
    int minMoves(vector<string>& classroom, int energy) {
      m = classroom.size();
      n = classroom[0].size();
      unordered_map<long long,int> corToIdx;
      int startX,startY,litterCount = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
          if (classroom[i][j] == 'L') {
            long long cor = encode(i,j);
            corToIdx[cor] = litterCount;
            litterCount++;
          } else if (classroom[i][j] == 'S') {
            startX = i;
            startY = j;
          }
        }
      }
      if (litterCount == 0) return 0;

      int targetMask = (1 << litterCount) - 1;
      vector<vector<vector<vector<int>>>> dist(
        m,vector<vector<vector<int>>>(
          n,vector<vector<int>>(
            energy+1,vector<int>(
              1<<litterCount , -1))));
      
      queue<tuple<int, int, int, int>> qu;
      dist[startX][startY][energy][0] = 0;
      qu.push({startX, startY, energy, 0});

      while (!qu.empty()) {
        auto [x, y, currEnergy, mask] = qu.front();
        qu.pop();
        int move = dist[x][y][currEnergy][mask];
        if (mask == targetMask) {
          return move;
        }
        if (currEnergy == 0) {
          continue;
        }

        for (auto [dx, dy] : directions) {
          int nX = x + dx;
          int nY = y + dy;
          int newMask = mask;
          int newEnergy = currEnergy-1;

          if (nX < 0 || nX >= m || nY < 0 || nY >= n || classroom[nX][nY] == 'X') {
            continue;
          }
          if (classroom[nX][nY] == 'L') {
            int litter_idx = corToIdx[encode(nX,nY)];
            newMask |= (1 << litter_idx);
          }
          if (classroom[nX][nY] == 'R') {
            newEnergy = energy;
          }
          if (dist[nX][nY][newEnergy][newMask] == -1 ||
              move + 1 < dist[nX][nY][newEnergy][newMask]) {
            dist[nX][nY][newEnergy][newMask] = move + 1;
            qu.push({nX, nY, newEnergy, newMask});
          }
        }
      }
      return -1;
    }

    inline long long encode(int x ,int y) {
      return ((long long) x << 32) | (unsigned int) y;
    }
    


    vector<pair<int,int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};


/*
shortest path + visit all requeired location
in this 
*/
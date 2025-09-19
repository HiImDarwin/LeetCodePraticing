class Solution {
  unordered_map<int, int> row, col;
  unordered_set<long long> lampSet;
  unordered_map<int,int> diag1, diag2;
  int N;
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
      N = n;
      for (auto& vec : lamps) {
        long long x = vec[0];
        int y = vec[1];
        if (lampSet.find((x << 32) + y) == lampSet.end()) {
          row[x]++;
          col[y]++;
          diag1[x - y]++;
          diag2[x + y]++;
          lampSet.insert((x << 32) + y);
        }
      }

      vector<int> res;
      for (auto& query : queries) {
        int x = query[0];
        int y = query[1];
        res.push_back(checklight(x,y));
        turnOff(x, y);
      }
      return res;
    }

    int checklight(long long x, int y) {

      if (row.find(x) != row.end() || col.find(y) != col.end()) {
        return 1;
      }
      if (diag1.find(x - y) != diag1.end() || diag2.find(x + y) != diag2.end()) {
        return 1;
      }
      return 0;
    }

    void turnOff(long long x , int y) {
      for (auto& [dx, dy] : gridDirs) {
        long long neiX = x + dx;
        int neiY = y + dy;
        if (lampSet.find((neiX << 32) + neiY) != lampSet.end()) {
          if (--row[neiX] == 0) row.erase(neiX);
          if (--col[neiY] == 0) col.erase(neiY);
          if (--diag1[neiX - neiY] == 0) diag1.erase(neiX - neiY);
          if (--diag2[neiX + neiY] == 0) diag2.erase(neiX + neiY);
          lampSet.erase((neiX << 32) + neiY);
        }
      }
    }
    vector<pair<int,int>> gridDirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, 
                                     {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};


/*
check col row diagonal
how to quickly check diagonal?


checkLight
turnOff


*/
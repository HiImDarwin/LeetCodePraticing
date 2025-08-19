class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<long long> rowPreSum(m,0);
      vector<long long> colPreSum(n,0);
      unordered_map<long long,vector<pair<int,int>>> NumSet;
      unordered_set<long long> Set;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          rowPreSum[i] +=  grid[i][j];
          colPreSum[j] +=  grid[i][j];
          NumSet[grid[i][j]].push_back({i,j});
        }
      }

      for (int i = 0; i < m; ++i) {
        if (i != 0) {
          rowPreSum[i] += rowPreSum[i - 1];
        }
        Set.insert(rowPreSum[i]);
      }

      for (int j = 0; j < n; ++j) {
        if (j != 0) {
          colPreSum[j] += colPreSum[j - 1];
        }
        Set.insert(colPreSum[j]);
      }
      
      if (rowPreSum[m-1]%2 == 0 && Set.find(rowPreSum[m-1]/2) != Set.end()) {
        cout << "5";
        return true;
      }

      for (int i = 0; i < m - 1; i++) {
        long long up = rowPreSum[i];
        long long down = rowPreSum[m-1] - rowPreSum[i];
        if (NumSet.find(abs(down - up)) != NumSet.end()) {
          int num = llabs(down - up);
          auto& vec = NumSet[num];
          for (auto& [x,y] : vec){
            if (up > down && x <= i) {
              if (n == 1 && i!=0 && (x==0 ||x ==i)) {
                return true;
              } else if (n!=1 && (i > 0 || y == 0 || y == n-1)) {
                cout << "3";
                return true;
              }
            } else if (up < down && x > i) {
              if (n == 1 && i!= m-2 && (x == i+1 || x == m-1)) {
                return true;
              } else if (n!=1 && (i != m-2 || y == 0 || y == n-1)) {
                cout << "4";
                return true;
              }
            }
          }
        }
      }

      for (int i = 0; i < n - 1; i++) {
        long long left = colPreSum[i];
        long long right = colPreSum[n-1] - colPreSum[i];
        if (NumSet.find(abs(left - right)) != NumSet.end()) {
          int num = llabs(left - right);
          auto& vec = NumSet[num];
          for (auto& [x, y] : vec){
            if (left > right && y <= i) {
              if ((m==1 && i!=0) && (y==0 || y==i)) {
                return true;
              } else if (m!=1 &&(i != 0 || x == 0 || x == m-1)) {
                cout << "1";
                return true;
              }
            } else if (left < right && y > i) {
              if ((m == 1 && i != n-2) && (y == i+1 || y == n-1)) {
                return true;
              } else if ( m!=1 &&(i != n-2 || x == 0 || x == m-1)) {
                cout << "2";
                return true;
              }
            }
          }
        }
      }

      return false;
    }
};
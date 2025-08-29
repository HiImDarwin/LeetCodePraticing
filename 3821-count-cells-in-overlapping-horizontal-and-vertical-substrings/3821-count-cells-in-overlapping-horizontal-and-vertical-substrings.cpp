class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
      int m = grid.size();
      int n = grid[0].size();
      
      vector<int> lsp = buildLsp(pattern);
      vector<vector<int>> rowHit(m, vector<int>(n,0));
      vector<vector<int>> colHit(m, vector<int>(n,0));

      int len = 0;
      for (int i = 0; i < m * n; i++) {
        while (len > 0 && grid[i / n][i % n] != pattern[len]) {
          len = lsp[len - 1];
        }
        if (grid[i / n][i % n] == pattern[len]) {
          len++;
        }
        if (len == pattern.length()) {
          int x = (i - pattern.length() + 1) / n;
          int y = (i - pattern.length() + 1) % n;
          int endX = (i+1) / n;
          int endY = (i+1) % n;
          rowHit[x][y]++;
          if (i != m * n - 1) rowHit[endX][endY]--;
          len = lsp[len - 1];
        } 
      }
      len = 0;
      
      for (int i = 0; i < m * n; i++) {
        while (len > 0 && grid[i % m][i / m] != pattern[len]) {
          len = lsp[len - 1];
        }
        if (grid[i % m][i / m] == pattern[len]) {
          len++;
        }
        if (len == pattern.length()) {
          int x = (i - pattern.length() + 1) % m;
          int y = (i - pattern.length() + 1) / m;
          int endX = (i + 1) % m;
          int endY = (i + 1) / m;
          colHit[x][y]++;
          if (i != m * n - 1) colHit[endX][endY]--;
          len = lsp[len - 1];
        } 
      }
      
      for (int i = 1; i < m*n; i++) {
        int x = i / n;
        int y = i % n;
        int prevX = (i - 1) / n;
        int prevY = (i - 1) % n;
        rowHit[x][y] += rowHit[prevX][prevY];
      }
      for (int i = 1; i < m*n; i++) {
        int x = i % m;
        int y = i / m;
        int prevX = (i - 1) % m;
        int prevY = (i - 1) / m;
        colHit[x][y] += colHit[prevX][prevY];
      }


  
      int res = 0;
      for (int i = 0; i < m ; i++) {
        for (int j = 0; j < n; j++) {
          if (rowHit[i][j] > 0 && colHit[i][j] > 0){
            res++;
          }
        }
      }
      
      return res;
    }

    vector<int> buildLsp(string& pattern) {
      int n = pattern.length();
      vector<int> lsp(n,0);
      int len = 0;
      for (int i = 1; i < n; i++){
        while (len != 0 && pattern[i] != pattern[len]) {
          len = lsp[len - 1];
        }
        if (pattern[i] == pattern[len]) {
          len++;
        }
        lsp[i] = len;
      }

      return lsp;   
    }
};


/*
KMP


*/
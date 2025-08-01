class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
      vector<vector<int>> d(n, vector<int>(n, 100000));
      for (auto& r: roads) {
        d[r[0]][r[1]] = min(d[r[0]][r[1]], r[2]);
        d[r[1]][r[0]] = min(d[r[1]][r[0]], r[2]);
      }
      int comb = 1 << n, res = 1;
      for (int mask = 1; mask < comb; ++mask) {
        res += getMaxDistance(mask, n, d) <= maxDistance;
      }
      return res;
    }

    int getMaxDistance(int mask, int n , vector<vector<int>> d) {
      int res = 0;
      for (int k = 0; k < n; ++k) {
          if ((mask & (1 << k)) == 0) continue;
          for (int i = 0; i < n; ++i) {
              if (i == k || (mask & (1 << i)) == 0) continue;
              for (int j = 0; j < n; ++j) {
                  if ((mask & (1 << j)) == 0 || i == j) continue;
                  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
              }
          }
      }

      for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) continue;
        for (int j = i+1; j < n; ++j) {
          if((mask & (1 << j))== 0) continue;
          res = max (res, d[i][j]);
        }
      }

      return res;
    }

    
};

/*
connected
undirected

for any a b dist > maxDistance need to close one company of it
choose which?
greedy way - consider how many node take it as middle node of minPath 
how to record how many path need this node 
*/



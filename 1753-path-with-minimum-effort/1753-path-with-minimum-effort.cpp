class Solution {
  vector<int> group;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();

      vector<vector<int>> edges;

      for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          vector<int> tmp1,tmp2;
          if (i+1 < m) {
            tmp1.push_back(abs(heights[i][j]-heights[i+1][j]));
            tmp1.push_back(i*n+j);
            tmp1.push_back((i+1)*n+j);
            edges.push_back(tmp1);
          }
          if (j+1 < n) {
            tmp2.push_back(abs(heights[i][j]-heights[i][j+1]));
            tmp2.push_back(i*n+j);
            tmp2.push_back(i*n+j+1);
            edges.push_back(tmp2);
          } 
        }
      }
      sort(edges.begin(), edges.end());
      group.resize(m*n);
      iota(group.begin(), group.end(),0);
      
      int start = 0, end = m*n-1;

      for (int i = 0; i < edges.size(); i++) {
        UniteGroup(edges[i][1],edges[i][2]);
        if (FindRoot(start) == FindRoot(end)) {
          return edges[i][0];
        }
      }

      return 0;
    }

    int FindRoot(int x) {
      if (group[x] != x) {
        group[x] = FindRoot(group[x]);
      }
      return group[x];
    }
    bool UniteGroup(int x, int y) {
      int xGroup = FindRoot(x);
      int yGroup = FindRoot(y);
      if (xGroup == yGroup) return false;
      if(xGroup > yGroup) {
        swap(xGroup,yGroup);
      }
      group[yGroup] = xGroup;
      return true;
    }
};

/*
  dijkstra
  
*/
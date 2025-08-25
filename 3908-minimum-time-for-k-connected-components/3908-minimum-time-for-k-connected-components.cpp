class Solution {
    vector<int> group;
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
      group.resize(n);
      iota(group.begin(), group.end(), 0);
      // u v time  
      sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] > b[2];
      });
      int connected = n;
      int time = INT_MAX;
      int idx = 0;
      while (idx < edges.size() && connected >= k) {
        int u = edges[idx][0];
        int v = edges[idx][1];
        time = edges[idx][2];
        if (unite(u,v)) {
          connected--;
        }
        idx++;
      }
      
      return connected >= k ? 0 : time;
    }
    int find(int x) {
      if (group[x] != x) {
        group[x] = find(group[x]);
      }
      return group[x];
    }

    bool unite (int x, int y) {
      int xGroup = find(x);
      int yGroup = find(y);
      if (yGroup == xGroup) return false;
      if (xGroup < yGroup) {
        swap(xGroup, yGroup);
      }
      group[xGroup] = yGroup;
      return true;
    }
};

/*
reverse union find

*/
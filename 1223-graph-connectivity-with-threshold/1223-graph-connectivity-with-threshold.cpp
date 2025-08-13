class Solution {
  vector<int> parent;
  int FindParent(int x) {
    if (parent[x] != x) {
      parent[x] = FindParent(parent[x]);
    }
    return parent[x];
  }

  bool Unite(int x, int y) {
    int xP = FindParent(x);
    int yP = FindParent(y);
    if (xP == yP) return false;
    if (xP > yP) {
      swap(xP, yP);
    }
    parent[yP] = xP;
    return true;
  }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
      parent.resize(n);
      iota(parent.begin(),parent.end(),0);
      for (int i = threshold + 1; i <= n; ++i) {
        for (int j = i*2; j <= n; j += i) {
          Unite(i-1, j-1);
        }
      }
      vector<bool> res;
      for (auto& query : queries) {
        int x = query[0]-1;
        int y = query[1]-1;
        if (FindParent(x) == FindParent(y)) {
          res.push_back(true);
        } else {
          res.push_back(false);
        }
      }
      return res;
    }
};

/*
  時間複雜度
  n/1 + n/2 + n/3 + n/4 + n/5 + ... + n/n = n * (1 + 1/2 + 1/3 + 1/4 + ... + 1/n) = O (n log n)
  調和級數是log n

*/
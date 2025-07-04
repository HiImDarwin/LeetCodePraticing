class TreeAncestor {
  vector<vector<int>> p;
public:
    TreeAncestor(int n, vector<int>& parent) {
      p.resize(n,vector<int>(20,-1));
      for(int i = 0; i < n; ++i) {
        p[i][0] = parent[i];
      }
      for(int j = 1; j < 20; j++) {  //更新長距離
        for(int i = 1; i<n; i++) {
          if(p[i][j-1] != -1)
            p[i][j] = p[p[i][j-1]][j-1]; 
        }
      }
    }
    int getKthAncestor(int node, int k) {
      for(int i = 0; i < 20 & node!= -1; ++i) {
        if(k & (1 << i)) 
          node = p[node][i];
      }
      return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


/*
the node will be 5*1e4
queries time will be 5*1e4
log(5*1e4) * 5*1e4 will more than 1e6 times 
can't use brute force





*/
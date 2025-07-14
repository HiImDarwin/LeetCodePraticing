class Solution {
  vector<int> bobDist;
  unordered_map<int,vector<int>> adj;
  int res = INT_MIN/2;
  int bob;
  vector<int> amount;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
      int n = amount.size();
      this->bob = bob;
      this->amount = amount;
      bobDist.resize(n,INT_MAX/2);

      for (auto edge : edges) {
        int a = edge[0], b = edge[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      dfs(0 ,-1 );
      dfs2(0 ,-1, 0, 0);
      return res;
    }
    void dfs(int cur, int parent) {
      if (cur == bob) {
        bobDist[cur] = 0;
        return;
      }
      int toBob = INT_MAX/2;
      for(int nxt : adj[cur]) {
        if(nxt == parent) continue;
        dfs(nxt, cur);
        toBob = min(toBob,bobDist[nxt]+1);
      }
      bobDist[cur] = toBob;
    }
    void dfs2(int cur, int parent, int step, int total) {
      if(step < bobDist[cur]) {
        total += amount[cur];
      } else if (step == bobDist[cur]) {
        total += amount[cur]/2;
      }
      if(adj[cur].size() == 1 && adj[cur][0] == parent){
        res = max(res,total);
        return;
      }
      for (int neighbor : adj[cur]) {
        if(neighbor == parent) continue;
        dfs2(neighbor, cur, step+1, total);
      }
    }
};


/*
node 0 ~ n-1


one to leaf 
one to root

undirected tree 

* alice and bob only meets once ?

alice - find best path to leaf
      DFS
bob - find the bob in the dfs
  cal the height of bob
  they meet at middle - pay half
  way to bob node don't need to pay
  after bob node keep going


  use a vector to record the path cost
  if find bob
    change the wieght in amount

*/
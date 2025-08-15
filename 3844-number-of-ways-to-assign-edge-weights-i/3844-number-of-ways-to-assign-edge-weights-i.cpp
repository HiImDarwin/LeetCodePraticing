class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
      int n = edges.size()+1;
      vector<vector<int>> adj(n+1);
      int MOD = 1e9+7;
      
      for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      
      int depth = dfs(1, -1, adj);
      int pathEdgeCount = depth - 1;
      GetFactorial(pathEdgeCount);
      int res = 0;
      for (int oneConut = 1; oneConut <= pathEdgeCount; oneConut += 2) {
        res = (res +comb(pathEdgeCount, oneConut)) % MOD;
      }
      return res;
    }

    int dfs(int node, int parent, vector<vector<int>>& adj) {
      int max_child_depth = 0;
      for (auto neighbor : adj[node]) {
        if (neighbor == parent) continue;
        max_child_depth = max(max_child_depth,dfs(neighbor, node, adj));
      }
      return max_child_depth + 1;
    }
    // vector<long long> C;
    // void buildComb(long long m) {
    //   int MOD = 1e9+7;
    //   C.assign(m+1,0);
    //   C[0] = 1;
    //   for (long long k = 1; k <= m; k++) {
    //     C[k] = (C[k-1] * (m - k + 1) / k ) % MOD;
    //   }
    // }

    const long long MOD = 1e9+7;
    vector<long long> factorial;
    void GetFactorial(long long n) {
      factorial.resize(n+1,0);
      factorial[0] = 1;
      for (int i = 1; i <= n; i++){
        factorial[i] = factorial[i-1] * i % MOD;
      }
    }

    long long quickPow(long long x, long long N) {
      if (N == 0) {
        return 1;
      }
      long long y = quickPow(x, N/2) % MOD;
      return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
    }

    long long comb(long long m, long long n) {
      if (n > m) return 0;
      long long a = factorial[m];
      long long b = factorial[n] * factorial[m-n] % MOD;
      long long inv_b = quickPow(b, (MOD-2));
      return a * inv_b % MOD;
    }
};
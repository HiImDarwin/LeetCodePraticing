class Solution {
public:
  //   vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
  //     unordered_set<string> variables;
  //     unordered_map<string,vector<pair<string,double>>> mp;
  //     for (int i = 0; i < equations.size(); i++) {
  //       string x = equations[i][0];
  //       string y = equations[i][1];
  //       double value = values[i];
  //       variables.insert(x);
  //       variables.insert(y);
  //       mp[x].push_back({y, value});
  //       mp[y].push_back({x, 1.0/value});
  //     }

  //     vector<double> res;
  //     for (auto q : queries) {
  //       string c = q[0];
  //       string d = q[1];
        
  //       if (variables.find(c) == variables.end() || variables.find(d) == variables.end()) {
  //         res.push_back(-1.0);
  //       } else {
  //         unordered_set<string> visited;
  //         res.push_back(dfs(c, d, mp, visited, 1.0));
  //       }
  //     }
  //     return res;
  //   }
  // private:
  //   double dfs(string node, string target, unordered_map<string,vector<pair<string,double>>>& mp, 
  //              unordered_set<string>& visited, double val) {
  //     if (node == target) {
  //       return val;
  //     }
  //     visited.insert(node);
  //     for (auto [next, weight] : mp[node]) {
  //       if (visited.find(next) != visited.end()) {
  //         continue;
  //       }
  //       double res = dfs(next, target, mp, visited, val * weight);
  //       if (res != -1.0) {
  //         return res;
  //       }
  //     }
  //     return -1.0;
  //   }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> id;
    double a[40][40] = {0};
    int n = 0;

    for (int i = 0; i < 40; i++) {
      for (int j = 0; j < 40; j++) {
        a[i][j] = -1.0;
      }
    }
    for (int i = 0; i < values.size(); i ++)
        {
            if (id.find(equations[i][0]) == id.end()) id[equations[i][0]] = n++;
            if (id.find(equations[i][1]) == id.end()) id[equations[i][1]] = n++;
            int x = id[equations[i][0]];
            int y = id[equations[i][1]];
            a[x][y] = values[i];
            a[y][x] = 1.0 / values[i];
        }
        //floyd to find all path in O(n^3)
        for (int k = 0; k < n; k ++)
            for (int i = 0; i < n; i ++)
                if (i != k)
                    for (int j = 0; j < n; j ++)
                        if (j != i && j != k && a[i][k] > 0 && a[k][j] > 0 && a[i][j] < 0)
                            a[i][j] = a[i][k] * a[k][j];
        // a/a = 1.0
        for (int i = 0; i < n; i ++) a[i][i] = 1.0;
        
        vector<double> res;
        for (auto x:queries)
        {
            if (id.find(x[0]) == id.end() || id.find(x[1]) == id.end()) res.push_back(-1.0);
            else res.push_back(a[id[x[0]]][id[x[1]]]);
        }
        return res;
    }
};

/*
  floyd warshell (n^3 + m)


  DFS (m * n)

*/
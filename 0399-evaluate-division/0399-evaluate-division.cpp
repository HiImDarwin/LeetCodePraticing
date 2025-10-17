class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      unordered_set<string> variables;
      unordered_map<string,vector<pair<string,double>>> mp;
      for (int i = 0; i < equations.size(); i++) {
        string x = equations[i][0];
        string y = equations[i][1];
        double value = values[i];
        variables.insert(x);
        variables.insert(y);
        mp[x].push_back({y, value});
        mp[y].push_back({x, 1.0/value});
      }

      vector<double> res;
      for (auto q : queries) {
        string c = q[0];
        string d = q[1];
        
        if (variables.find(c) == variables.end() || variables.find(d) == variables.end()) {
          res.push_back(-1.0);
        } else {
          unordered_set<string> visited;
          res.push_back(dfs(c, d, mp, visited, 1.0));
        }
      }
      return res;
    }
  private:
    double dfs(string node, string target, unordered_map<string,vector<pair<string,double>>>& mp, 
               unordered_set<string>& visited, double val) {
      if (node == target) {
        return val;
      }
      visited.insert(node);
      for (auto [next, weight] : mp[node]) {
        if (visited.find(next) != visited.end()) {
          continue;
        }
        double res = dfs(next, target, mp, visited, val * weight);
        if (res != -1.0) {
          return res;
        }
      }
      return -1.0;
    }
};

/*
  floyd warshell


  DFS (m * n)

*/
class Solution {
private:

struct disjoint {
  disjoint(int nodeNum) {
    par.resize(nodeNum);
    for (int i = 0; i < nodeNum; i++) {
      par[i] = i;
    }
  }
  vector<int> par;
  int find(int x) {
    if (par[x] != x) {
      par[x] = find(par[x]);
    }
    return par[x];
  }

  void uni(int x, int y) {
    int x_par = find(x);
    int y_par = find(y);
    par[y_par] = x_par;
  }
};

public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    struct disjoint dsj(n);
    unordered_map<string,vector<int>> mp;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        mp[accounts[i][j]].push_back(i);
      }
    }
    for (auto node : mp) {
      if (node.second.size() == 1) {
        continue;
      }
      for (int i = 0; i < node.second.size(); i++) {
        dsj.uni(node.second[0],  node.second[i]);
      }
    }

    unordered_map<int,set<string>> newAccounts;

    for (int i = 0; i < n; i++) {
      int idx = dsj.find(i);
      for(int j = 1; j < accounts[i].size(); j++) {
        newAccounts[idx].insert(accounts[i][j]);
      }
    }
    vector<vector<string>> res;
    for (auto s : newAccounts) {
      vector<string> tmp;
      tmp.push_back(accounts[s.first][0]);
      tmp.insert(tmp.end(), s.second.begin(), s.second.end());
      res.push_back(tmp);
    }

    return res;
  }
};




// for the same name view as node may connect
// same account name only show once
// unordered_map<string, vector<int>> account link with name index
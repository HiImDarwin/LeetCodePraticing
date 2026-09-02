class Solution {
private:

struct disjoint {
  disjoint(int nodeNum): par(nodeNum) {
    iota(par.begin(), par.end(), 0);
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
    unordered_map<string,int> emailOwner;

    for(int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        string &email = accounts[i][j];
        if (emailOwner.count(email) == 0) {
          emailOwner[email] = i;
        } else {
          dsj.uni(i, emailOwner[email]);
        }
      }
    }

    unordered_map<int, vector<string>> groups;
    for (auto& [email, owner] : emailOwner) {
      int root = dsj.find(owner);
      groups[root].push_back(email);
    }

    vector<vector<string>> res;
    
    for (auto& [idx , vec] : groups) {
      sort(vec.begin(), vec.end());
      vector<string> accout;
      accout.push_back(accounts[idx][0]);
      accout.insert(accout.end(),
        vec.begin(),
        vec.end()
      );

      res.push_back(move(accout));
    }
    return res;
  }
};



// multi name may be in same group (and may not) > so should use index to distinct each one
// each email is unique
// email is the link between multi name 

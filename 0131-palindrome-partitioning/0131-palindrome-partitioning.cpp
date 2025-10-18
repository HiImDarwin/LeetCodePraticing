class Solution {
  vector<vector<bool>> memo;
  public:
    vector<vector<string>> partition(string s) {
      int n = s.length();
      vector<string> sol;
      vector<vector<string>> res;
      memo.resize(n, vector<bool>(n,false));
      recursive(s, 0, sol, res);
      return res;
    }

    void recursive(const string& s, int idx, vector<string> &sol, vector<vector<string>>& res) {
      if (idx == s.length()) {
        res.push_back(sol);
        return;
      }
      for (int i = idx; i < s.length(); i++) {
        if (s[i] == s[idx] && (i - 1 < idx + 1 || memo[idx + 1][i - 1])) {
          memo[idx][i] = true;
          sol.push_back(s.substr(idx, i - idx + 1));
          recursive(s, i + 1, sol, res);
          sol.pop_back();
        }
      }
    }
};

/*
recursive way


*/
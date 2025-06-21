class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> res;
      vector<int> sol;
      backtracking(n, k ,res ,sol ,1);
      return res;
    }
    void backtracking(int n, int k, vector<vector<int>> & res, vector<int> &sol, int start) {
      if(k == 0) res.push_back(sol);
      if(start > n) return;
      for(int i = start; i <= (n - k + 1); i++) {
        sol.push_back(i);
        backtracking(n, k-1, res, sol, i+1);
        sol.pop_back();
      }
    }
};
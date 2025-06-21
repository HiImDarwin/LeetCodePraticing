class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
      vector<vector<int>> res;
      vector<int> sol;
      vector<bool> visited(nums.size(), false);
      backtracking(nums ,res, sol, visited, 0);
      return res;
    }
    void backtracking(vector<int> &nums,vector<vector<int>> &res, vector<int> &sol,vector<bool> &visited, int count) {
      if(count == nums.size()) res.push_back(sol);

      for(int i = 0; i< nums.size(); ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        sol.push_back(nums[i]);
        backtracking(nums, res, sol, visited, count+1);
        visited[i] = false;
        sol.pop_back();
      }
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> sol;

      sort(nums.begin(), nums.end());
      recursive(nums, 0, sol, res);
      return res;
    }

    void recursive(vector<int>& nums, int idx, vector<int>& sol, vector<vector<int>>& res) {
      res.push_back(sol);
      if (idx == nums.size()) {
        return;
      }
      for (int i = idx; i < nums.size(); i++) {
        if (i != idx && nums[i] == nums[i - 1]) {
          continue;
        }
        sol.push_back(nums[i]);
        recursive(nums, i + 1, sol, res);
        sol.pop_back();
      }
    }
};
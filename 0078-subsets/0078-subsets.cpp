class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> res((1<<n));
      res[0] = {};
      for (int i = 0; i < (1 << n); i++) {
        vector<int>& tmp = res[i];
        for(int j = 0; j < n; j++) {
          if ((i >> j) & 1) continue;
          int mask = i | (1 << j);
          vector<int>& tmp = res[mask];
          tmp = res[i];
          tmp.push_back(nums[j]);
        }
      }
      return res;
    }
};
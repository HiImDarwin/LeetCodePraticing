class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      //sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      recursive(nums, 0, res);
      return res;
    }

    void recursive(vector<int>& nums, int idx, vector<vector<int>>& res) {
      if (idx == nums.size()) {
        res.push_back(nums);
      }
      unordered_set<int> st;
      for (int i = idx; i < nums.size(); i++) {
        if (st.find(nums[i]) != st.end()) continue;
        swap(nums[i],nums[idx]);
        st.insert(nums[idx]);
        recursive(nums, idx + 1, res);
        swap(nums[i],nums[idx]);
      }
    }
};
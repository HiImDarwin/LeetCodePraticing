class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      recursive(nums, 0, res);
      return res;
    }

    void recursive(vector<int>& nums, int index, vector<vector<int>>& res) {
      if (index == nums.size()) {
        res.push_back(nums);
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        recursive(nums, index + 1, res);
        swap(nums[i], nums[index]);
      }
    }
};


/*
位置交換


*/
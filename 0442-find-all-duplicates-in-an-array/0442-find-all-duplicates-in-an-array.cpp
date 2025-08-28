class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n = nums.size();
      vector<int> res;

      for (int i = 0; i < n; i++){
        if (nums[i] - 1 == i) {
          continue;
        } else {
          while (nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (nums[i] != i+1) {
          res.push_back(nums[i]);
        }
      }

      return res;
    }
};
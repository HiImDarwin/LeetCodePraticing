class Solution {
public:
    int minDeletion(vector<int>& nums) {
      int n = nums.size();
      int deleteCount = 0;
      for (int i = 0; i < n; ++i) {
        if ((i - deleteCount)%2 == 0 && i+1 < n && nums[i] == nums[i+1]) {
          deleteCount++;
        }
      }
      if ((n - deleteCount)%2) {
        deleteCount++;
      }
      return deleteCount;
    }
};
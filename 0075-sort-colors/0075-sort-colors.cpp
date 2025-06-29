class Solution {
  public:
    void sortColors(vector<int>& nums) {
      int n = nums.size();
      int rIdx = 0, wIdx = 0, bIdx = n-1;
      while(wIdx <= bIdx) {
        if(nums[wIdx] == 0) {
          swap(nums[wIdx],nums[rIdx]);
          rIdx++;
          wIdx++;
        } else if (nums[wIdx] == 1) {
          wIdx++;
        } else {
          swap(nums[wIdx],nums[bIdx]);
          bIdx--;
        }
      }
    }
};
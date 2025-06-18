class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
      if(left>=right) return;
      int pivot = nums[left];
      int lt = left;
      int i = left+1;
      int gt = right;

      while( i <= gt) {
        if (nums[i] < pivot) {
          swap(nums[i++], nums[lt++]);
        } else if (nums[i] == pivot) {
          i++;
        } else {
          swap(nums[i], nums[gt--]);
        }
      }

      quickSort(nums,left,lt-1);
      quickSort(nums,gt+1,right);
    }
};
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
      int diff = nums[0];
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (nums[mid] - diff - mid >= k) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      return nums[left] + (k - (nums[left] - diff - left));
    }
};

/*

[x,o,o,x,o,o,o,x,o,x,];
 4     7       11  13
offset of num = nums[i] - diff - i
*/
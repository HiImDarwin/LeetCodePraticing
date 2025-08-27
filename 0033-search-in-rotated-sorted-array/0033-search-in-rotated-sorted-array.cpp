class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int left = 0, right = n-1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
          return mid;
        }
        if (nums[left] <= nums[mid]) { // <= 很重要 因為你是left+ (right -left) 靠左
          if (nums[mid] > target && target >= nums[left]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        } else {
          if (nums[mid] < target && target <= nums[right]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
      }
      return -1;
    }
};





/*

1 2 3 4 5 6 7

5 6 7 1 2 3 4 


5 6 7 1 2

6 7 1 2 3

XXXXXXXXXOOO
        ^
XXOOOOOOO
       ^
XXOOOOOOO
 ^      

1. check if we are in rotate part
  *  mid < right && mid > left  : normal
  *  mid > right > abnormal
  *  mid < left > abnormal

2. shift according to 1

*/
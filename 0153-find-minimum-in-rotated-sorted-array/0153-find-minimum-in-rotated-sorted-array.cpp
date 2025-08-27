class Solution {
public:
    // this way is find the pivot point
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();
    //     int left =0;
    //     int right = n;
    //     while(left < right) {
    //         int mid = left + (right-left)/2;
    //         if(nums[mid] > nums[left]) left =mid;
    //         else right = mid;
    //     }
    //     return nums[(left+1)%n];
    // }
    // int findMin(vector<int>& nums) {
    //     int right = nums.size()-1;
    //     int left = 0;

    //     while(left < right) {
    //       int mid = left + (right - left) / 2;
    //       if(nums[mid] > nums[right]) {
    //         left = mid + 1;
    //       } else {
    //         right = mid;
    //       }
    //     }
    //     return nums[left];
    // }
    int findMin(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;

      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
          right = mid;
        } else if (nums[mid] > nums[right]) {
          left = mid + 1;
        }
      }
      return nums[left];
    }
};






/*

the array right shift 
[4 5 6 1 2 3]

[1 2 3 4 5 6]

desing Bin Search
the order is increasing and I want the min value
i will let the mid be on left side


Question
will there be dulplicate value?
time limited in this question?
how long will be size of array
value range won't be a problem


*/
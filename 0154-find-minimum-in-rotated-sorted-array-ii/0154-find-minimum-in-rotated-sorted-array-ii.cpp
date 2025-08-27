class Solution {
public:
    // int findMin(vector<int>& nums) {
    //   int right = nums.size()-1;
    //   int left = 0;
    //   while(left < right) {
    //     while(left < right && nums[left] == nums[left+1]){
    //       left++;
    //     }
    //     while(left < right && nums[right] == nums[right-1]){
    //       right--;
    //     }
    //     if(left == right) break;

    //     int mid = left + (right - left) / 2;
        
    //     if(nums[mid] < nums[right]) {
    //       right = mid;
    //     } else {
    //       left = mid + 1;
    //     }
    //   }
    //   return nums[left];
    // }

    int findMin(vector<int>& nums) {
      int left = 0, right = nums.size()-1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
          right = mid;
        } else if (nums[mid] > nums[right]) {
          left = mid + 1;
        } else {
          right--;
        }
      }
      return nums[left];
    }
};




/*
array is rotated

[1 2 3 4 4 5 5 6 7]

[6 7 1 2 3 4 4 5 5]

[4 1 4 4 4 4 4]
 l   r         r

[4 4 4 4 4 5 6 7 1 4]
 l       l          r


the value of array is in accesding
i will make the mid indx on left

question 
 * Value duplicate? Yes
 * value range ?
 * array size ?
 

*/
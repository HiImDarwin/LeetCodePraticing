class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int left = 1, right =1;
      while(right < n) {
        if (nums[right] != nums[right-1]){
          nums[left] = nums[right];
          left++;
        }
        right++;
      }
      return left;
    }
};
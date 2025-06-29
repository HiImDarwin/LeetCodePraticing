class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if(n < 2) return n;
      int left = 1, right = 2;
      while(right < n) {
        if(nums[right] == nums[left] && nums[right] == nums[left-1]) {
          right++;
        } else {
          left++;
          nums[left] = nums[right];
          right++;
        }
        
      }
      return left+1; 
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[i] == n || nums[i] == i) {
          continue;
        }
        while(nums[nums[i]] != nums[i]) {
          swap(nums[nums[i]], nums[i]);
          if (nums[i] == n) {
            break;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        if (nums[i] != i) return i;
      }

      return n;
    }
};


/*





*/
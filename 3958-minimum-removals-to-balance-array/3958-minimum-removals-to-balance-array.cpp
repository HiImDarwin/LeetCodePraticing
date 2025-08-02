class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      if(1LL * nums[0] * k >= nums[n-1]) return 0;

      int length = 0;
      for(int i = 0; i < n; i++) {
        if(1LL * nums[i]*k > nums[n-1]) {
          length = max(length, n-i);
          break;
        }
        int right = upper_bound(nums.begin(),nums.end(), nums[i]*k) - nums.begin();
        length = max(length, right - i);
      }
      return n - length;
    }
};


/*
  [2,1,5], k = 2
  1 > 2
  5 NOT exist



  [1,6,2,9] k = 3
  1 > 3 2 > 6
  9 > 3 6 > 2
*/
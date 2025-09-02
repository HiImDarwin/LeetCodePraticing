class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int threshold) {
      int left = 1, right =  INT_MAX;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(nums, threshold, mid)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }

    bool check (vector<int>& nums, int threshold, int divisor) {
      int sum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        sum += (nums[i] / divisor) + ((nums[i] % divisor == 0) ? 0 : 1);
      }
      return sum <= threshold;
    } 
};


/*

           ???XXXXXXX


*/
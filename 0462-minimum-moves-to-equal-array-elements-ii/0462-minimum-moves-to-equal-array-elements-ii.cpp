#include <algorithm>

class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int N = nums.size();
      std::sort(nums.begin(), nums.end());
      int midian = nums[N/2];
      int res = 0;
      for (int i = 0; i < N; i++) {
        res += abs(nums[i] - midian);
      }
      return res;
    }
};
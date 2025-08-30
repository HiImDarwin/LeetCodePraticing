class Solution {
public:
    int maximumGap(vector<int>& nums) {
      if (nums.size() <= 1) return 0;
      int maxVal = *max_element(nums.begin(), nums.end());

      long exp = 1;
      int radix = 10;

      vector<int> tmp(nums.size());
      while (maxVal / exp > 0) {
        vector<int> count(radix, 0);
        for (int i = 0; i < nums.size(); ++i) {
          count[(nums[i] / exp) % 10]++;
        }

        for (int i = 1; i < count.size(); ++i) {
          count[i] += count[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
          tmp[--count[(nums[i] / exp) % 10]] = nums[i];
        }

        swap(nums,tmp);

        exp *= 10;
      }

      int maxGap = 0;
      for(int i = 0; i < nums.size() - 1; i++) {
        maxGap = max(nums[i + 1] - nums[i], maxGap);
      }

      return maxGap;
    }
};

/*

is their sorting algo in O(n)?


*/
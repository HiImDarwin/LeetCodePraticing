class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
      int n = nums.size();
      vector<int> count(101, 0);
      for (int i = 0; i < k; i++) {
        count[nums[i] + 50]++;
      }
      vector<int> res;
      res.push_back(beauty(count, x));

      for (int i = k; i < n; i++) {
        count[nums[i] + 50]++;
        count[nums[i - k] + 50]--;
        res.push_back(beauty(count, x));
      }

      return res;
    }

    int beauty(vector<int>& count,int x) {
      int negativeSum = 0;
      for (int i = 0; i < 50; i++) {
        negativeSum += count[i];
        if (negativeSum >= x) {
          return i - 50;
        }
      }
      return 0;
    } 
};
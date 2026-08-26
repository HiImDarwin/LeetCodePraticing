class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int> count;
      for (int num : nums) {
        count[num]++;
      }
      int maxVal = nums[0];
      int appear = 0;
      for (pair<int,int> x : count) {
        if (x.second > appear) {
          maxVal = x.first;
          appear = x.second;
        }
      }
      return maxVal;
    }
};

// 4
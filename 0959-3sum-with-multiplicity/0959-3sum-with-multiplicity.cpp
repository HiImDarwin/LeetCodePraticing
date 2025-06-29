class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      long  res = 0;
      long  M = 1e9 + 7;
      for (int j = 1; j < n-1; ++j) {
        int k = n-1;
        for(int i = 0; i < j; ++i) {
          int count1 = 1;
          int count2 = 0;

          while( i+1 < j && nums[i+1] == nums[i]) {
            count1++;
            i++;
          }
          while(k > j && nums[i] + nums[j] + nums[k] > target) {
            k--;
          }
          while(k > j && nums[i] + nums[j] + nums[k] == target) {
            count2++;
            k--;
          }
          res += count1*count2;
          res %= M;
        }
      }
      return res;
    }   
};

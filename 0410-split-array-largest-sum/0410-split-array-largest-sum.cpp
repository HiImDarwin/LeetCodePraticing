class Solution {
public:
    // int splitArray(vector<int>& nums, int k) {
    //   int left = *max_element(nums.begin(), nums.end());
    //   int right = accumulate(nums.begin(), nums.end(), 0);
    //   while (left < right) {
    //     int mid = left + (right - left) / 2;
    //     if (check(nums, mid, k)) {
    //       right = mid;
    //     } else {
    //       left = mid + 1;
    //     }
    //   }
    //   return left;
    // }

    // bool check(const vector<int>& nums,const int val, const int k) {
    //   int n = nums.size();
    //   int sum = 0;
    //   int partitionConut = 1;

    //   for (int i = 0; i < n; i++) {        
    //     if (sum + nums[i] > val) {
    //       sum = nums[i];
    //       partitionConut++;
    //     } else {
    //       sum += nums[i];
    //     }
    //   }
    //   return partitionConut <= k;
    // }

    int splitArray(vector<int>& nums, int k) {

      int n = nums.size();
      vector<vector<long>> dp(n + 1, vector<long>(k + 1, INT_MAX));
      nums.insert(nums.begin(), 0);
      dp[0][0] = 0;

      for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= min(k, i); s++) {
          long sum = 0;
          for (int j = i; j >= s; j--) {
            sum += nums[j];
            dp[i][s] = min(dp[i][s],max(dp[j - 1][s - 1], sum));
          }
        }
      }

      return dp[n][k];
    }
};


/*
  1. how to split
    at most n - k + 1 element
    at least 1 element
    can't tell which splite way is the best
  2. 


brute force
  C(n - 1,k - 1) split way
  O(n^k)
  find all split way with recursive and use prefix Sum to find the min max


dp
dp[i][k] split 1~i into k part minMax Val


binary search
  min max >= totolSum/k
  find all possiable subarray sum check if the rest can build up a subset < than it
*/
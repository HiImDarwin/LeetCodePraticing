class Solution {
    int modulo;
    int k;
  public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
      int n = nums.size();
      int count = 0;
      unordered_map<int, long long> mp; // module value, frequency
      mp[0]++;
      long long res = 0;

      for (int i = 0; i < n; i++) {
        count += (nums[i] % modulo == k);
        int m = count % modulo;
        int kk = (m - k + modulo) % modulo;

        res += mp[kk];
        mp[m]++;
      }

      return res;
    }
};

/*
Your task is to find the count of subarrays that are interesting.
  
[x x x x x]
 ^       ^


cnt % module = k
cnt = (module * times) + k

k == 0
*/
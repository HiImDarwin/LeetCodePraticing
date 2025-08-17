class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<long long> reamind(k, LLONG_MIN);
      reamind[0] = 0;
      long long dp = 0, pref = 0, sum = 0;
      for (int i = 0; i < n; i++) {
        sum += nums[i];
        pref += nums[i];
        int r = pref % k;

        if (reamind[r] != LLONG_MIN) {
          dp = max(dp, reamind[r] + pref);
        }
        reamind[r] = max(reamind[r], dp - pref);
      }
      return sum - dp;
    }
};
/*

reminder必須存 %k 以前的
＊ prefixSum
＊ 已經做的區間


XXXXXXXXXXXX
 |___| |____|
*/
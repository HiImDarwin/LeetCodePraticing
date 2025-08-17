class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<long long> remain(k,LLONG_MIN);
      long long preSum = 0, deleteSum = 0;
      remain[0] = 0;
      for (int i = 1; i <= nums.size(); ++i) {
        preSum += nums[i-1];
        int r = preSum % k;
        if (remain[r] != LLONG_MIN) {
          deleteSum = max(deleteSum, preSum + remain[r]);
        }
        remain[r] = max(remain[r], deleteSum - preSum);
      }
      return preSum - deleteSum;
    }
};


/*

reminder必須存 %k 以前的
＊ prefixSum
＊ 已經做的區間
// dp 目前可以刪除的最大區間
// pref 目前的前綴和
// reamind[r] = 已知的最佳 offset（狀態轉移需要的資訊）
// 在此r之前的 


X XXXXXX
 |___| j   i

 prefi(i) - prefix(j) + previousDP
 prefix[j] = previousDP - prefix(i)
*/
// class Solution {
// public:
//     int splitArray(vector<int>& nums, int k) {
//         long minK = *max_element(nums.begin(), nums.end());
//         long maxK = accumulate(nums.begin(),nums.end(),0);
//         while(minK <maxK) {
//           long mid = minK + (maxK - minK) / 2;
//           if(isOK(nums, k, mid)) {
//             maxK = mid;
//           } else {
//             minK = mid + 1;
//           }
//         }
//         return minK;
//     }

//     bool isOK(vector<int> &nums, int k , long val) {
//       int count = 0;
//       for (int i = 0; i<nums.size(); ++i) {
//         if(nums[i] > val) return false;

//         int j = i;
//         long sum = 0;
//         while(j < nums.size() && sum + nums[j] <= val) {
//           sum += nums[j];
//           j++;
//         }
//         count++;
//         i = j-1;
//       }
//       return count <= k;
//     }

// };
class Solution {
  public:
    // int splitArray(vector<int>& nums, int k) {
    //   int n = nums.size();
    //   nums.insert(nums.begin(),0);
    //   vector<vector<long>> dp(n+1,vector<long>(k+1,INT_MAX));
    //   dp[0][0] = 0;
    //   for(int i = 1; i <= n; ++i) {
    //     for(int x=1; x<=min(k,i);x++) {
    //       long sum = 0;
    //       for(int j =i; j>=x; j--) {
    //         sum+=nums[j];
    //         dp[i][x] = min(dp[i][x], max(dp[j-1][x-1], sum));
    //       }
    //     }
    //   }
    //   return dp[n][k];
    // }
    int splitArray(vector<int>& nums, int k) {
      int n =nums.size();
      nums.insert(nums.begin(),0);
      vector<vector<long>> dp(k+1,vector<long>(n + 1,LONG_MAX));
      std::vector<long long> prefixSum(n + 1, 0);
      for(int i = 1; i<=n;++i) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
      }

      dp[0][0] = 0;

      for(int group = 1; group <= k; ++group) {
        for(int i = 1; i<=n; ++i) {
          for (int j = 0; j < i; ++j) {
            if (j >= group - 1) { 
              long current_group_sum = prefixSum[i] - prefixSum[j];
              if (dp[group - 1][j] != LLONG_MAX) 
                dp[group][i] = min(dp[group][i],max(dp[group-1][j],current_group_sum));
            }
          }
        }
      }
      return dp[k][n];
    }
};
/*
splite array into k non-empty subarray
largest sum of any array i minimized



way 1 DP

DP[k][i] means max value when divided array into k group from 0 ~i element 

Dp initialization
  when 0 group dp[0][i] should all be 0
  there are some case that array can't divied 
  we used -1 to represent it
Dp status transfer
  dp[i][j] =max( min(dp[i-1][j-1]: dp[i-1][j-n]) )
  前 j 個元素分成 k-1份的左有可能 與 sum[i]-sum[j] 找出最大
  j的範圍 (k-1 ~ i-1)

way 2 Binary Seach
a: the minimum sum may be the maximun element value of array
b: the maximym sum is the array sumup
so we can used binary search [a,b]

how do we check if array can meet number i ?
we used greedy way to check sumup < i 

here is the key concept 
if we can spilte array under val i less than k group
than we can splite it into k group (if the element num is enough)
so when we spliting the group 
we can go greedy way


*/
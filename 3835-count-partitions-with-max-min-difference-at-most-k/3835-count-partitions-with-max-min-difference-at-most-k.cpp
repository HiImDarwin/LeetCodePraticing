class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
      int n = nums.size();
      nums.insert(nums.begin(),0);
      int MOD = 1e9 + 7;
      vector<int> dp(n+1,0);
      vector<long long> prefixSum(n+1);
      prefixSum[0] = 1;
      dp[0] = 1;
      deque<int> maxQueue,minQueue;
      int left = 1;
      
      for(int i = 1; i < nums.size(); i++) {
        while (!maxQueue.empty() && nums[maxQueue.back()] < nums[i]) {
          maxQueue.pop_back();
        }
        while (!minQueue.empty() && nums[minQueue.back()] > nums[i]) {
          minQueue.pop_back();
        }
        maxQueue.push_back(i);
        minQueue.push_back(i);

        while(left <=i && nums[maxQueue.front()] - nums[minQueue.front()] > k) {
          if(maxQueue.front() == left) {
            maxQueue.pop_front();
          }
          if(minQueue.front() == left) {
            minQueue.pop_front();
          }
          left++;
        }
        // 如果我是 i 的合法區間 [j...i] 那麼我需要的和是 j-1 + j +... + i-1 所以是prefixSum[i-1] - prefixSum[j-2]
        //left是對應最左邊的 element


        dp[i] = prefixSum[i-1] - (left - 2 >= 0 ? prefixSum[left - 2] : 0);
        prefixSum[i] = prefixSum[i - 1] + dp[i];

        dp[i] = (dp[i] + MOD) % MOD;
        prefixSum[i] = (prefixSum[i] + MOD) % MOD;          
      }

      return dp[n];
    }
};

/*

dp[i] =  total number of ways to partition from 0~i
state transfer dp[i] = sumup(dp[j-1]:dp[i-1]);

X X X X X X X i
      ^
      j
      max min - i <=k

      
      
* dp[i]
* prefixsum for dp[i];
* monotonic queue to solve segment max/min problem

*/
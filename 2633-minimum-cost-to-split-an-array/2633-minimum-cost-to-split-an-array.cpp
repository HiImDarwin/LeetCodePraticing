class Solution {
public:
    int minCost(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> dp(n,INT_MAX);


      for (int i = 0; i < n; i++) {
        unordered_map<int,int> mp;
        int score = 0;
        for(int j = i; j >= 0; j--) {
          mp[nums[j]]++;
          if (mp[nums[j]] == 2) {
            score += 2;
          } else if (mp[nums[j]] > 2) {
            score++;
          }
          dp[i] = min(dp[i], k + score + (j-1 < 0 ? 0 : dp[j-1]));
        }
      }
      return dp[n-1];
    }
};

/*

dp[i]:  minimum possible cost of a split of nums.
splite more  > more times of k

splite less > may have higher importance value


how we chose splite or not 
if [i:j]  importance value > k +[i: o] + [o:j] than we splite 


*/
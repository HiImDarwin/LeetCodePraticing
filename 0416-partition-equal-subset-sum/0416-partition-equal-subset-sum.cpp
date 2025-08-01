class Solution {
public:

    //backtracking TLE
    // bool canPartition(vector<int>& nums) {
    //     int total = 0;
    //     for(int &x :nums) {
    //         total+=x;
    //     }
    //     if(total%2 != 0) return false;
    //     int target = total/2;
    //     sort(nums.begin(),nums.end());
    //     int set=0;
    //     return backtracking(nums, target,0, set);

    // }

    // bool backtracking(vector<int>& nums, int target,int index, int &sum) {
    //     if(sum == target) return true;
    //     if(index == nums.size()) return false;
    //     if((sum+nums[index])>target) return false;
    //     sum+=nums[index];
    //     bool res1 = backtracking(nums, target,index+1, sum);
    //     sum-=nums[index];
    //     bool res2 =backtracking(nums, target,index+1, sum);
    //     return (res1 || res2 );
        
    // }

    bool canPartition(vector<int>& nums) {
      
      int target = accumulate(nums.begin(), nums.end(), 0);
      if(target %2 == 1) return false;
      target /= 2;
      vector<bool> dp(target+1,false);
      dp[0] = true;
      for(int num : nums) {
        for(int i = target ; i >= 0; --i) {
          if(i - num <0) continue;
          dp[i] = dp[i] || dp[i - num];
        }
      }
      return dp[target];
    }
};
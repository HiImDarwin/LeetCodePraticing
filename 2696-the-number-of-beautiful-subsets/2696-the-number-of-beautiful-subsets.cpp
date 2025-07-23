class Solution {
public:
    // int beautifulSubsets(vector<int>& nums, int k) {
    //   int res = 0;
    //   sort(nums.begin(),nums.end());
    //   unordered_set<int> forbiddenNums;
    //   backtracking(nums, k, 0, forbiddenNums, res);
    //   return res;
    // }

    // void backtracking(vector<int>& nums, int k, int index, unordered_set<int> &forbiddenNums, int &count) {
    //   for(int i = index; i < nums.size(); i++) {
    //     if(forbiddenNums.count(nums[i])) continue;
    //     count++;
    //     forbiddenNums.insert(nums[i]+k);
    //     backtracking(nums, k ,i+1, forbiddenNums, count);
    //     forbiddenNums.erase(nums[i]+k);
    //   }
    // }
    int beautifulSubsets(vector<int>& nums, int k) {
      int ans = 0;
      unordered_map<int,int> mp;
      dfs(nums, 0, k, mp, ans);
      return ans - 1;
    }

    void dfs(vector<int> &nums, int idx, int k, unordered_map<int,int> &mp, int &ans) {
      if(idx == nums.size()) ans++;
      else {
        if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
          mp[nums[idx]]++;
          dfs(nums, idx+1, k, mp, ans);
          mp[nums[idx]]--;
        }
        dfs(nums, idx + 1, k, mp, ans);
      }
    }
};


/*

question
1. is there duplicate element in nums?




1. DP
2. Backtracking
*/
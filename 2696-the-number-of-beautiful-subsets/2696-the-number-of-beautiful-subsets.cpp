class Solution {
  public:
    int beautifulSubsets(vector<int>& nums, int k) {
      n_ = nums.size();
      k_ = k;
      sort(nums.begin(), nums.end());
      int count;
      unordered_map<int,int> mp;
      return recursive(nums, 0, mp) - 1;
      
    }
  private:
    int recursive(vector<int>& nums, int idx, unordered_map<int,int>& mp) {
      if (idx == n_) {
        return 1;
      }
      int count = 1;
      for (int i = idx; i < n_; i++) {
        if (mp.find(nums[i] - k_) != mp.end() || mp.find(nums[i] + k_) != mp.end()) {
          continue;
        }
        mp[nums[i]]++;
        count += recursive(nums, i + 1, mp);
        mp[nums[i]]--;
        if (mp[nums[i]] == 0) {
          mp.erase(nums[i]);
        }
      }

      return count;
    }
    int k_;
    int n_;
    
};

/*
  1. recursive building subset
  [x,x,x,x,x,x,x,x,x]



*/
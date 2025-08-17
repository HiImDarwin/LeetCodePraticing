class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<long long, int> mp;
        mp[0] = 0;
        int curSubCount = 0;
        long long prefixSum = 0;
        for (int i = 1; i <= nums.size(); i++) {
          prefixSum += nums[i-1];
          if (mp.find(prefixSum - target) != mp.end()) {
            curSubCount = max(curSubCount, mp[prefixSum - target] + 1);
          }
          mp[prefixSum] = curSubCount;
        }
        return curSubCount;
    }
};

/*
num - x = target
num - target = x


*/
class Solution {
public:
  // vector<int> twoSum(vector<int>& nums, int target) {
  //   unordered_map<int,vector<int>> index;
  //   for(int i = 0; i < nums.size(); i++) {
  //     index[nums[i]].push_back(i);
  //   }
  //   sort(nums.begin(), nums.end());
  //   int front = 0;
  //   int end = nums.size() - 1;
  //   while (front < end) {
  //     if (nums[front] + nums[end] < target) {
  //       front++;
  //     } else if (nums[front] + nums[end] > target) {
  //       end--;
  //     } else {
  //       break;
  //     }
  //   }

  //   vector<int> ans(2);
  //   ans[0] = index[nums[front]].back();
  //   index[nums[front]].pop_back();
  //   ans[1] = index[nums[end]].back();
  //   return ans;
  // }

  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> record;
    vector<int> ans(2);
    for (int i = 0; i < nums.size(); i++) {
      if (record.find(target - nums[i]) != record.end()) {
        ans[0] = record[target - nums[i]];
        ans[1] = i;
        break;
      }
      record[nums[i]] = i;
    }
    return ans;
  }
};
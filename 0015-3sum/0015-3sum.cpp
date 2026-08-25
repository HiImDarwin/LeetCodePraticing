class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int k = nums.size() - 1; k > 1; k-- ) {
      if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {
        continue;
      }
      int i = 0;
      int j = k - 1;
      int target = -nums[k];
      
      while(i < j) {
        if (nums[i] + nums[j] > target) {
          j--;
        } else if (nums[i] + nums[j] < target) {
          i++;
        } else {
          res.push_back({nums[i], nums[j], nums[k]});
          while(i + 1 < j && nums[i] == nums[i + 1]) {
            i++;
          }
          i++;
          while(j - 1 > i && nums[j] == nums[j - 1]) {
            j--;
          }
          j--;
        }
      }


    }
    return res;
  }

};


// duplicate triplets means no 3 same position in other order
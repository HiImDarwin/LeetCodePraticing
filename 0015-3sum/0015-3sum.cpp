class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n = nums.size();
      vector<vector<int>> res;
      for(int target = 0; target < n - 2; ++target) {
        int targetNum = -nums[target];
        int left = target+1;
        int right = n-1;
        while(left < right){
          if(nums[left] + nums[right] < targetNum) left++;
          else if(nums[left] + nums[right] > targetNum ) right--;
          else {
            res.push_back({nums[target],nums[left],nums[right]});
            left++;
            right--;
            while(left < right && nums[left] == nums[left-1]) {
              left++;
            } 
            while(left < right && nums[right+1] == nums[right]) {
              right --;
            }
          }
        }
        while(target < n-2 && nums[target] == nums[target+1]) target++;
      }
      return res;
    }
};


// i + j + k = 0
// change the thought to  i + j = -k become a two sum problem and can check wtih two pointer
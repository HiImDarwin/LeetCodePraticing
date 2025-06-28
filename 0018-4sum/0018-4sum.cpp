class Solution {
public:
    //這題難再剪枝 如何刪去不需要重覆地部分
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n  = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      for(int leftFix = 0; leftFix < n-3 ; ++leftFix) {
        for( int rightFix = n-1; rightFix > leftFix + 2; --rightFix) {
          int left = leftFix + 1;
          int right = rightFix -1;
          long long targetNum = (long long)target - nums[leftFix] - nums[rightFix];
          while(left < right) {
            if(nums[left] + nums[right] > targetNum) {
              right--;
            } else if (nums[left] + nums[right] < targetNum) {
              left++;
            } else {
              res.push_back({nums[leftFix],nums[left],nums[right],nums[rightFix]});
              left++;
              right--;
              while(left < right && nums[left] == nums[left-1]){
                left++;
              }
              while(left < right && nums[right] == nums[right+1]){
                right--;
              }
            }
          }
          while(rightFix > leftFix + 2 && nums[rightFix] == nums[rightFix-1]){
            rightFix--;
          }
        }
        while(leftFix < n-3 && nums[leftFix] == nums[leftFix+1]){
            leftFix++;
        }
      }
      return res;
    }
};



// corner case which will come up with multi same result
// [2,2,2,2,2,2]
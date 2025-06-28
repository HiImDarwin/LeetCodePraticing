class Solution {
public:
    // backtracking 會提供所有組合的解，O(n^3)
    // int threeSumClosest(vector<int>& nums, int target) {
    //     //sorting + backtracking
    //     sort(nums.begin(),nums.end());
    //     backtracking(nums,target,0,0,0);
    //     return closesSum;

        
    // }

    // void backtracking(vector<int>& nums,int target,int start,int count,int currentSum) {
    //     if(count == 3) {
    //         int diff = abs(currentSum-target);
    //         if(diff < minDiff) {
    //             minDiff = diff;
    //             closesSum = currentSum;
    //         }
    //         return;
    //     }
    //     for(int i= start; i<nums.size();++i) {
    //         backtracking(nums, target, i + 1, count + 1, currentSum + nums[i]);
    //     }

    // }
    // int minDiff = INT_MAX;
    // int closesSum;

    
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int res = INT_MAX/2;
      for(int fix = 0; fix < n - 2; ++fix) {
        int targetNum = target - nums[fix];
        int low = fix + 1;
        int high = n-1;
        while(low < high) {
          res = abs(res-target) > abs(nums[low] + nums[high] + nums[fix] - target) ?
                nums[low] + nums[high] + nums[fix] :
                res;
          if(nums[low] + nums[high] > targetNum) {
            high--;
          } else if (nums[low] + nums[high] < targetNum) {
            low++;
          } else {
            return target;
          }
        }
      }
      return res;
    }
};
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int left = *max_element(weights.begin(), weights.end()); 
      int right = accumulate(weights.begin(), weights.end(), 0);
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (needDay(weights , mid) > days) {
          left = mid + 1;
        } else {
          right = mid;
        }

      }
      return left;
    }

    int needDay(vector<int>& nums, int weight) {
      int totalDays = 0;
      int weightSum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (weightSum + nums[i] <= weight) {
          weightSum += nums[i];
        } else {
          totalDays++;
          weightSum = nums[i];
        }
      }
      if (weightSum > 0) {
        totalDays++;
      }
      return totalDays;
    }
};

/*

least weight capacity of the ship 
shipped within days days.

 weight go higer days needed go lower
 lowest wieght

*/
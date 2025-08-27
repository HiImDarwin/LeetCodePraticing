class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
      int n = nums.size(); 
      vector<long long> preSum(n+1,0);
      preSum[0] = 0;
      for (int i = 1; i <= n; ++i) {
        preSum[i] = nums[i-1] + preSum[i - 1];
      }
      long long left = 1, right = preSum.back();
      while (left < right) {
        long long mid = left + (right - left) / 2;
        if (countSub(nums, mid) >= k) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }


    // int countSub(vector<long long>& preSum, int middle) {
    //   int n = preSum.size();
    //   int count = 0;
      
    //   // for (int i = 1; i < n; i++) {
    //   //   for (int j = i-1; j >= 0; j--) {
    //   //     if (preSum[i] - preSum[j] <= middle) {
    //   //       count++;
    //   //     } else {
    //   //       break;
    //   //     }
    //   //   }
    //   // }
    //   for (int i = 0, j = 1; j < n; j++) {
    //     while(i < j && (preSum[j] - preSum[i]) > middle) {
    //       i++;
    //     }
    //     count += j - i;
    //   }
    //   return count;
    // }

    int countSub(vector<int>& nums, int target) {
      int n = nums.size();
      int count = 0;
      int total = 0;
      for (int left = 0, right = 0; right < n; right++) {
	      total += nums[right];
	      while (left <= right && total > target) {
		      total -= nums[left];
		      left++;
	      }
	      count += right - left + 1;
      }
      return count;
    }
};


/*

binary Search + 


val = mid



XXXXXXXOOOOO XXXXXXXXXXXX
    ^           ^
*/
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
      int n = arr.size();
      sort(arr.begin(), arr.end());
      vector<int> preSum(arr.size() + 1, 0);
      for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + arr[i - 1];
      }
      
      int left = 0;
      int right = arr.back();

      while (left < right) {
        int mid = left + (right - left) / 2;
        int sum = getSum(arr, preSum, mid);
        if (sum < target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      int sum1 = getSum(arr, preSum, left);
      int sum2 = getSum(arr, preSum, left - 1);
      return abs(sum1 - target) < abs(sum2 - target) ? left : left - 1;
    }


    int getSum(vector<int>& arr, vector<int>& preSum, int upperBound) {
      int idx = lower_bound(arr.begin(), arr.end(), upperBound) - arr.begin();
      int sum = preSum[idx] + (arr.size() - idx) * upperBound;
      return sum;
    }
};


/*
assume a asscending array
[x,x,x,x,x,x,x,x,x,x,x]
 ^                   ^


check if the 


what is sum < taregt?
*/
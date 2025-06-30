class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
      int n = nums.size();
      int M = 1e9 + 7;
      sort(nums.begin(), nums.end());
      vector<long> powerOf2(n,1);
      for(int i = 1; i < n; ++i) {
        powerOf2[i] = (powerOf2[i-1] * 2)% M;
      }

      long res = 0;
      for(int i = 0, j = n-1; i < n; i++) {
        while(j >= i  && nums[i] + nums[j] > target) {
          j--;
        }
        if( j < i ) break;

        res = (res + powerOf2[j-i]) % M;
      }
      return res;
    }
};


/*


subsequence > so we can't sort the array!
No we can sort the array because the result ask for num of subsequence

use sliding window to find 
[X X X X X X]
     m     M

how to find the next max or min?
monotonic stack find the smaller or bigger element on right side
*/
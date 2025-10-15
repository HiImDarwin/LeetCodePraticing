class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
      int n = nums.size();
      vector<int> bitCount(32,0);
      vector<int> maxOr(n + 1,0);
      for (int i = n - 1; i >= 0; i--) {
        maxOr[i] = maxOr[i + 1] | nums[i];
      }

      vector<int> res;
      int right = 0;
      int sum = 0;
      for (int i = 0; i < n ;i++) {
        if (i > 0) {
          for (int j = 0; j < 32; j++) {
            if ((nums[i - 1] >> j ) & 1) {
              bitCount[j]--;
              if (bitCount[j] == 0) {
                sum &= ~(1 << j);
              }
            }
          }
        }

        while (right < n && sum < maxOr[i] || right == i) {
          right++;
          for (int j = 0; j < 32; j++) {
            if ((nums[right - 1] >> j) & 1) {
              bitCount[j]++;
              if (bitCount[j] == 1) {
                sum |= 1 << j;
              }
            }
          }
        }

        res.push_back(right - i);
      }
      return res;
    }
};

/*
1. do a  preOR for end of array
> we can know maxixmum num for each start

2. how to handle the window
  left = i 
  if (or num < maxNum for i) {
    right++
  }
3. how did u do when left++ > bit counting
  vector<int> bitCount(32)



[x,x,x,x,x,x,x,x]

we can do a 



*/
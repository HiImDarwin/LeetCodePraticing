class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

/*
--+
+++


all num > 0 

  num[N-3] * num[N-2] * num[N-1]

one element < 0
  num[N-3] * num[N-2] * num[N-1]
more than two element < 0
  max (num[N-3] * num[N-2] * num[N-1], num[N-1] * num[0] * num[1]);

one element > 0
  num[N-1] * num[0] * num[1]

all element < 0
  num[N-3] * num[N-2] * num[N-1]
  
*/
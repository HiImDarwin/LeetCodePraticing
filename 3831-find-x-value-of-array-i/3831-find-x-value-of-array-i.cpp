class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
      int n = nums.size();
      for (auto& num : nums) {
        num = num % k;
      }
      vector<long long> lastProduct(k);
      vector<long long> totalProduct(k);

      for (int i = 0; i < n; i++) {
        int current = nums[i];
        vector<long long> tmp(k);
        totalProduct[current]++;

        for (int j = 0; j < k; j++) {
          int newProd = (j * current) % k;
          tmp[newProd] += lastProduct[j];
          totalProduct[newProd] +=  lastProduct[j];
        }
        tmp[current]++;
        lastProduct = tmp;
      }
      return totalProduct; 
    }
};

/*
[x x x x] x x x x x x [x x x x x]
can subarray be empty ? can


 x-value: number of ways to perform this operation the product of the remaining elements leaves a remainder of x

1 % 3 = 1
2 % 3 = 2
3 % 3 = 0
4 % 3 = 1
7 % 3 = 1
a*b % q = r1
c*d % q = r2 

if i = 1
prefixSum of reminder

[1,2,3,4,5]

1 2 0 | 1 2

0 0 0 2 2

meet reminder = 0 presum reset


*/



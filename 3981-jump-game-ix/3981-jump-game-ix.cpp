class Solution {

public:
    vector<int> maxValue(vector<int>& nums) {
      int n = nums.size();
      vector<int> pre(n), suff(n), res(n);

      pre[0] = nums[0], suff[n-1] = nums[n-1];
      for (int i = 1; i < n; ++i) {
        pre[i] = max(nums[i], pre[i-1]);
      }

      for (int i = n-2; i >= 0; --i) {
        suff[i] = min(nums[i], suff[i+1]);
      }
      res[n-1] = pre[n-1];
      for (int i = n - 2; i >= 0; i--) {
        res[i] = pre[i];
        if (pre[i] > suff[i+1]) {
          res[i] = res[i+1];
        }
      }
      return res;
    }
};

/*

[5 4 2 10 1 20 2]
 

[5 5 5 10 10 20 20]
[1,1,1, 1, 1, 2, 2]



[,20,20]
2 20 1 10

find all i value
for each value 
 left larger
 right smaller

union find

left mostlargest stack


  
*/
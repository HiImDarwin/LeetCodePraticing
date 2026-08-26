class Solution {
public:
  // vector<int> productExceptSelf(vector<int>& nums) {
  //   int n = nums.size();

  //   vector<int> pre(n, 1),post(n, 1);
  //   int total = 1;
  //   for(int i = 0; i < n - 1; i++) {
  //     pre[i + 1] = pre[i] * nums[i];
  //   } 
  //   for(int i = n - 2; i >= 0; i--) {
  //     post[i] = post[i + 1] * nums[i + 1]; 
  //   }

  //   vector<int> res(n);
  //   for (int i = 0; i < n; i++) {
  //     res[i] = pre[i] * post[i];
  //   }

  //   return res;
  // }

  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n,1);
    int tmp = 1;
    for (int i = 1; i < n; i++) {
      res[i] = res[i - 1] * nums[i - 1]; 
    }
    for (int i = n - 1; i >= 0; i--) {
      res[i] = res[i] * tmp;
      tmp *= nums[i];
    }

    return res;
  }
};



// [2,2,2,2,2,2]
// [1,2,4,8,16,32]
// [32,16,8,4,2,1]



class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        float mid = -1.0*b/(2*a);
        int front = 0, end = n-1;
        vector<int> res;
        if(a == 0) {
          if(b < 0) reverse(nums.begin(),nums.end());
          for(int &x : nums){
            x = function(x,a,b,c);
          }
          return nums;
        }

        while (front<=end) {
          if(abs((float)nums[front] - mid) > abs((float)nums[end] - mid)){
            res.push_back(function(nums[front], a, b, c));
            front++;
          } else {
            res.push_back(function(nums[end], a, b, c));
            end--;
          }
        }

        if(a > 0) reverse(res.begin(), res.end());
        return res;
    }

    int function(int x, int a, int b , int c) {
      return x*x*a + x*b + c;
    }
};



/*
  a>0 開口向上
  最小值
  a<0 開口向下
  最大值

  can this be in-place
*/
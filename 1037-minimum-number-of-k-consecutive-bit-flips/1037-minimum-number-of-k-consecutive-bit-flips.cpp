class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> flipCount(n + 1,0);
      int cur = 0;
      int res = 0;
      for (int i = 0; i < n; i++) {
        int num = nums[i];
        cur += flipCount[i];
        if (((num + cur )% 2) == 0) {
          res++;
          cur++;
          if (i + k > nums.size()) return -1;
          flipCount[i + k]--;
        }
      }
      return res;
    }
};



/*

0 11111 0
we can hanle for 1 length < k-1
00000100000 

11001100111
   

count contineous  0
if == k flip
if < k count continuous 1

--11 1
  ----
     -----

int looking for
*/
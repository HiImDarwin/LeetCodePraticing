class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
      unordered_map<int,int> evenMp, oddMp;
      int n = nums.size();
      int idx = 0;
      for (int i = 0; i < n; i++)  {
        if(nums[i] == k) {
          idx = i;
          break;
        }
      }
      
      oddMp[0] = 1;

      int preSum = 0;
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (nums[i] > k) preSum++;
        if (nums[i] < k) preSum--;

        if (i >= idx)  {
          if (i%2 == 0) {
            res += oddMp[preSum];
            res += evenMp[preSum - 1];
          } else {
            res += evenMp[preSum];
            res += oddMp[preSum - 1];
          }
        } else {
           if (i%2 == 0) {
            evenMp[preSum]++;
          } else {
            oddMp[preSum]++;
          }
        }

      }

      return res;
    }
};

/*

 [3,2,1,4,5]


*/
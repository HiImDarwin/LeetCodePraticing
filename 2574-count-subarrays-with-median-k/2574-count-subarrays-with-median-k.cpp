class Solution {
public:
    // int countSubarrays(vector<int>& nums, int k) {
    //   unordered_map<int,int> evenMp, oddMp;
    //   int n = nums.size();
    //   int idx = 0;
    //   for (int i = 0; i < n; i++)  {
    //     if(nums[i] == k) {
    //       idx = i;
    //       break;
    //     }
    //   }
      
    //   oddMp[0] = 1;

    //   int preSum = 0;
    //   int res = 0;
    //   for (int i = 0; i < n; i++) {
    //     if (nums[i] > k) preSum++;
    //     if (nums[i] < k) preSum--;

    //     if (i >= idx)  {
    //       if (i%2 == 0) {
    //         res += oddMp[preSum];
    //         res += evenMp[preSum - 1];
    //       } else {
    //         res += evenMp[preSum];
    //         res += oddMp[preSum - 1];
    //       }
    //     } else {
    //        if (i%2 == 0) {
    //         evenMp[preSum]++;
    //       } else {
    //         oddMp[preSum]++;
    //       }
    //     }

    //   }

    //   return res;
    // }

    int countSubarrays(vector<int>& nums, int k) {
      int n = nums.size();
      int idx;
      for (int i = 0; i < n; i++) {
        if (nums[i] == k) {
          idx = i;
        }
      }

      unordered_map<int,int> prev, post;

      int count = 0;
      for (int i = idx - 1; i >= 0; i--) {
        count += nums[i] > k ? 1 : -1;
        prev[count]++;
      }

      count = 0;
      for (int i = idx + 1; i < n; i++) {
        count += nums[i] > k ? 1 : -1;
        post[count]++;
      }

      int res = 1;
      res += prev[0] + post[0] + post[1] + prev[1];
      for (auto [key, count] : prev) {
        int key1 = -key;
        int key2 = 1 - key;
        res += count * post[-key];
        res += count * post[1 - key];
      }
      return res;
    }
};

/*

 [3,2,1,4,5]


*/
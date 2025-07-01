class Solution {
public:
    // int triangleNumber(vector<int>& nums) {
    //   sort(nums.begin(), nums.end());
    //   int n = nums.size();
    //   int res = 0;
    //   for (int i = 0; i< n-2; i++) {
    //     for(int j = i + 1; j < n-1; j++) {
    //       for(int k = j + 1; k < n; k++) {
    //         if(nums[i] + nums[j] <= nums[k]) break;
    //         res++;
    //       }
    //     }
    //   }
    //   return res;
    // }
    int triangleNumber(vector<int>& nums) {
      int res = 0;
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int k = 0;
      while( k < n && nums[k] == 0) k++;
      for(int i = n-1; i >= k+2; --i) {
        int target = nums[i];
        int l = k;
        int r = i-1;
        while(l < r) {
          if(nums[l] + nums[r] > target) {
            res += r-l;
            r--;
          } else l++;
        }
      }
      return res;
    }

};


// for triangel two short side sum must bigger than the longest side 
// a + b > c

// so we have i j k three pointer
// fixed i can use `for` for add 1 per round
// in each round j and k  run throuh whole matrix

// In this case. We want to ask if the element in array is length or link
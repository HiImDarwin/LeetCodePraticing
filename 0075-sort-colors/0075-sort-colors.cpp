class Solution {
public:
  // void sortColors(vector<int>& nums) {
  //   vector<int> color(3,0);
  //   for (auto& num : nums) {
  //     color[num]++;
  //   }
  //   int idx = 0;
  //   for (int i = 0; i < nums.size(); i++) {
  //     while (color[idx] == 0) {
  //       idx++;
  //     }
  //     nums[i] = idx;
  //     color[idx]--;
  //   }
  // 

  // void sortColors(vector<int>& nums) {
  //   int whiteStart = 0;
  //   int blueStart = nums.size();
  //   int curr = 0;
  //   while (curr < nums.size() && curr < blueStart) {
  //     if (nums[curr] == 0) {
  //       swap(nums[curr], nums[whiteStart++]);
  //       curr++;
  //     } else if (nums[curr] == 2) {
  //       swap(nums[curr], nums[--blueStart]);
  //     } else {
  //       curr++;
  //     }
  //   }
  // }


  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int r_idx = 0;
    int b_idx = n - 1;
    int idx = 0;
    while (idx <= b_idx) {
      if (nums[idx] == 0) {
        nums[idx] = nums[r_idx];
        nums[r_idx++] = 0;
        idx++;
      } else if (nums[idx] == 2) {
        nums[idx] = nums[b_idx];
        nums[b_idx--] = 2;
      } else {
        idx++;
      }
    }
  }
};

/*


*/
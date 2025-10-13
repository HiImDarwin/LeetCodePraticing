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

  void sortColors(vector<int>& nums) {
    int whiteStart = 0;
    int blueStart = nums.size();
    int curr = 0;
    while (curr < nums.size() && curr < blueStart) {
      if (nums[curr] == 0) {
        swap(nums[curr], nums[whiteStart++]);
        curr++;
      } else if (nums[curr] == 2) {
        swap(nums[curr], nums[--blueStart]);
      } else {
        curr++;
      }
    }
  }
};

/*

two pointer

[red  white  blue]
    ^      ^

counting sort

*/
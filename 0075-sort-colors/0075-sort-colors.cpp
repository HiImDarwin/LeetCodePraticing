class Solution {
public:
  void sortColors(vector<int>& nums) {
    vector<int> color(3,0);
    for (auto& num : nums) {
      color[num]++;
    }
    int idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      while (color[idx] == 0) {
        idx++;
      }
      nums[i] = idx;
      color[idx]--;
    }
  }
};

/*

two pointer

[red  white  blue]
    ^      ^

counting sort

*/
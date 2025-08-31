class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k = k % n;
      int start = 0;
      int count = 0;
      while (count < n) {
        int current = start, prev = nums[start];
        do {
          int next = (current + k) % n;
          int tmp = nums[next];
          nums[next] = prev;
          prev = tmp;
          current = next;
          count++;
        } while (start != current);
        start++;
      }
    }
};

/*
build another array

used  unordere_map
indext sort


*/
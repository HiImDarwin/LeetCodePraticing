class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
      int left = *max_element(nums.begin(), nums.end());
      int right = accumulate(nums.begin(), nums.end(), 0);
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(nums, mid, k)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }

    bool check(const vector<int>& nums,const int val, const int k) {
      int n = nums.size();
      int sum = 0;
      int partitionConut = 1;

      for (int i = 0; i < n; i++) {        
        if (sum + nums[i] > val) {
          sum = nums[i];
          partitionConut++;
        } else {
          sum += nums[i];
        }
      }
      return partitionConut <= k;
    }
};


/*
  1. how to split
    at most n - k + 1 element
    at least 1 element
    can't tell which splite way is the best
  2. 


brute force
  C(n - 1,k - 1) split way
  O(n^k)
  find all split way with recursive and use prefix Sum to find the min max


binary search
  min max >= totolSum/k
  find all possiable subarray sum check if the rest can build up a subset < than it
*/
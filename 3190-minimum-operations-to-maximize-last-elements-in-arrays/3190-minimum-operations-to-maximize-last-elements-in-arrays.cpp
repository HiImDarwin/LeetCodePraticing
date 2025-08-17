class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.back() > nums2.back()) {
        return minOperations(nums2, nums1);
      }
      int n = nums1.size();
      int lastMax1 = nums1[n-1], lastMax2 = nums2[n-1];
      int needChange = 0, safeForBoth = 0;
      for (int i = 0; i < n; i ++) {
        if (nums2[i] > lastMax2) return -1;
        if (nums1[i] > lastMax1) {
          if (nums2[i] > lastMax1 || nums1[i] > lastMax2) {
            return -1;
          }
          needChange++;
        } else if (nums2[i] <= lastMax1) {
          safeForBoth++;
        }
      }
      return min(needChange, n-needChange-safeForBoth);
    }
};


/*

so we can peek the last value first
than we know the value shouldn't higher than that

than we count the num for both array
lower than last
higher than last   

[2,3,4,5,9] h:0
[8,8,4,4,4] h:2
a need change 
b need change
ab both need change 
ab don't need change

edge condition

 total num = 5 if h
*/
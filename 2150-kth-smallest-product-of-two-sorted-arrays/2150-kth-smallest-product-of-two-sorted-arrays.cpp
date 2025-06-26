class Solution {
  public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
      long long left = -1e10, right = 1e10;
      while(left < right) {
        long long mid = left +(right - left) / 2;
        if(countLessEqual(nums1, nums2, mid) < k) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    }

    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long x) {
      long long count = 0;
      int n = nums2.size();
      for(int i = 0; i< nums1.size(); ++i) {
        if(nums1[i] < 0) {
          long long sm = ceil((double)x/nums1[i]);
          int j = lower_bound(nums2.begin(), nums2.end(), sm) - nums2.begin();
          count += n-j;
        } else if (nums1[i] > 0) {
          long long sm = floor((double)x/nums1[i]);
          int j = upper_bound(nums2.begin(), nums2.end(),sm) -nums2.begin();
          count += j;
        } else {
          if(x >=0) count += n;
        }
      }
      return count;
    }
};
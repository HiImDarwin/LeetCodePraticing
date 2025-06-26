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
      for(int a: nums1) {
        if(a == 0) {
          if(x >= 0) count += n;
          continue;
        }
        int low = 0, high = nums2.size();
        while(low < high) {
          int mid = (low+high)/2;
          long long prod = 1LL* a * nums2[mid];
          if (prod <= x) {
            if(a > 0) low = mid + 1;
            else high = mid;
          } else {
            if (a > 0) high = mid;
            else low = mid+1;
          }
        }
        count += (a > 0)? low : (nums2.size() - low);
      }
      return count;
    }
};
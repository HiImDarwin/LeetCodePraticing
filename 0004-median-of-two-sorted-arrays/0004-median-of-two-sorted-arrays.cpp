class Solution {
public:
    //brute force
    // merege array
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> merged;
      merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
      int n = merged.size();
      return n%2 ? (double) merged[n/2] : ((merged[n/2]+merged[n/2-1])/2.0);
    }
};
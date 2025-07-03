class Solution {
  public:
    //brute force
    // merege array
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //   vector<int> merged;
    //   merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
    //   int n = merged.size();
    //   return n%2 ? (double) merged[n/2] : ((merged[n/2]+merged[n/2-1])/2.0);
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size();
      if((m+n)%2 == 1) return findKthElement(nums1,0, nums2, 0, (n + m) / 2 + 1);
      else return (findKthElement(nums1,0, nums2, 0, (n + m) / 2 ) 
                  + findKthElement(nums1,0, nums2, 0, (n + m) / 2 + 1))*1.0 / 2;
      
    }

    int findKthElement(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2, int k) {
      int m = nums1.size(), n = nums2.size();
      if(m-idx1 > n -idx2) return findKthElement(nums2, idx2, nums1, idx1 ,k);

      if(idx1 == m) return nums2[idx2+k-1];
      if(k == 1) return min(nums1[idx1], nums2[idx2]);


      int k1,k2;
      k1 = k/2 > (m-idx1) ? m-idx1: k/2;
      k2 = k - k1;
      if(nums1[idx1 + k1 -1] < nums2[idx2 + k2 - 1]) {
        return findKthElement(nums1, idx1+k1, nums2, idx2, k - k1);
      } else {
        return findKthElement(nums1, idx1, nums2, idx2+k2, k - k2);
      }

    }

};



/* 



used merege sort
O(m+n)

So the time complexity seems can't uses with literate the array

use binary Search in two array
we can guess the value of target
both return a index i and j
we want to find the one that i+j = m+n/2
This way the time com O(log(m*n));

[x x x x x x]
[y y y y y y y y y y ]

find k/2 element for each array assumn k = 6


[x x x] [x x x]
[y y y] [y y y y y y y y]
if x2 > y2 means [x0 x1] [y0 y1 y2] is smaller than the k element 
but x2 may bigger than the k element (because y > y2 may smaller than k)

next round
[x x x x]
[y y y y y y y y]  k = 6-5 = 1


*/
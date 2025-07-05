class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int right = arr.back() + k; // assume all element in array isn't missing anything
      int left  = 0;

      while(left < right) {
        int mid = right - (right - left) / 2;
        int M = mid - 1; // should have mid -1 element
        int T = lower_bound(arr.begin(),arr.end(),mid) -arr.begin(); //find the first >= mid element
        // this is the key key point  
        // we want the mid be the k missing one
        // so before mid we shoud got k-1 missing in [1~mid-1] interval
        if(M-T <= k-1) {
          left = mid;
        } else {
          right = mid-1;
        }
      }
      return left;
    }
};

/*

假设我们猜测mid是否是答案。考察[1,mid-1]这段连续自然数区间，
可知道这段区间的自然数有M个，并且有T个存在于数组中（即查找数组里有多少个小于mid的元素个数，利用lower_bound）。
所以，在[1,mid-1]这段连续自然数区间内有missing number = M-T个。理论上我们希望这段区间应该有missing number共k-1个，
于是就可以帮助判定mid是否偏大和偏小。
*/

/*

for normal condition
index i is for number i+1
bias = 1;
[1 2 4 5 6]
mid = 2 nums[mid] =4
4 - (mid+bias) -1 = 1

[1 2 4]
mid = 1
1 = 1+bias
left right 



*/
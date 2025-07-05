class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      int n = bloomDay.size();
      long total = 1L * m * k;
      if(total > n) return -1;
      int right = *max_element(bloomDay.begin(),bloomDay.end());
      int left = 1;
      while(left < right) {
        int mid = left + (right - left) / 2;
        if(haveMbouquet(bloomDay,m,k,mid)) {
          right = mid;
        } else {
          left = mid+1;
        }
      }
      return left;
    }

    bool haveMbouquet(vector<int>& bloomDay, int m, int k, int day) {
      int n = bloomDay.size();
      int l = 0,r = 0;
      int count = 0;
      while(l<n &&r < n) {
        if(bloomDay[l] > day) {
          l++;
          continue;
        }
        r = l+1;
        while(r < n && r-l <k && bloomDay[r] <= day){
          r++;
        }
        if(r-l == k) {
          count++;
        }
        l = r;
      }
      return count >= m;
    }
};



/*

m bouqets
k adjenct flower

we need m small subarrays that with
  maximum subarray value
  length k 


[x x x x x x x x x x x x x x x x x x]

from day 1 ~ day max





*/
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long minK = *max_element(nums.begin(), nums.end());
        long maxK = accumulate(nums.begin(),nums.end(),0);
        while(minK <maxK) {
          long mid = minK + (maxK - minK) / 2;
          if(isOK(nums, k, mid)) {
            maxK = mid;
          } else {
            minK = mid + 1;
          }
        }
        return minK;
    }

    bool isOK(vector<int> &nums, int k , long val) {
      int count = 0;
      for (int i = 0; i<nums.size(); ++i) {
        if(nums[i] > val) return false;

        int j = i;
        long sum = 0;
        while(j < nums.size() && sum + nums[j] <= val) {
          sum += nums[j];
          j++;
        }
        count++;
        i = j-1;
      }
      return count <= k;
    }



};



/*
splite array into k non-empty subarray
largest sum of any array i minimized



way 1 DP



way 2 Binary Seach
a: the minimum sum may be the maximun element value of array
b: the maximym sum is the array sumup
so we can used binary search [a,b]

how do we check if array can meet number i ?
we used greedy way to check sumup < i 

here is the key concept 
if we can spilte array under val i less than k group
than we can splite it into k group (if the element num is enough)
so when we spliting the group 
we can go greedy way


*/
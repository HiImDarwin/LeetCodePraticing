class Solution {
public:
//     int maxFrequency(vector<int>& nums, int k) {
//       sort(nums.begin(), nums.end());
//       int n = nums.size();
//       nums.insert(nums.begin(), 0);
//       vector<long long> presum(n+1);
//       for(int i = 1; i <= n; ++i) 
//         presum[i] = presum[i - 1] + nums[i];
      
//       int i = 1;
//       int res = 0;
//       for (int j = 1; j <= n; ++j) {
//         while(!isOK(nums, presum, i ,j ,k))
//           i++;
//         res = max(res,j - i + 1);
//       }
//       return res;
//     }

//     bool isOK(vector<int> &nums, vector<long long> &presum, int i, int j, int k) {
//       long long delta = (long long)nums[j] * (j - i + 1) - (presum[j] -presum[i -1]);
//       return delta <=k;
//     }
    int maxFrequency(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int res = 0;
      long long totalSum = 0;
      for(int i = 0,j = 0; i < n; ++i) {
        totalSum += nums[i];
        long long opNum = (long long)nums[i]*(i-j+1) - totalSum;

        while(opNum > k) {
          totalSum -= nums[j];
          j++;
          opNum = (long long)nums[i]*(i-j+1) - totalSum;
        }
        res = max(res, i-j+1);
      }
      return res;
    }
}; 



/*
[1 , 2 , 4] k =5
the window size is maximum num of element that can
be change to same charater
the num need for operation is  difference for every num to max(min) num

so the maximum window size will be the answer (wrong)


cornor case

[1 2 10 1 1 1 1] k = 1
the max window size will be 4
that's not correct 
when calculation the res also need to consider the num of char which is in window
find tha maximum one and let every one change to it
so! if the k is far more than the window size

You don't need do modified a adjency num
you can edit all num in array
so just sort the array than you can view the problem with window
and the most frequency is the window width

*/
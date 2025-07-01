class Solution {
public:
    // prefix Sum + hash 
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //   int n = nums.size();
    //   unordered_map<int,int> map; //prefix -> count of idx
    //   map[0] = 1; // 0個1 的 prefix count
    //   int res = 0;
    //   int preSum = 0;
    //   for(int i = 0 ; i < n; ++i) {
    //     preSum += nums[i];
    //     if(map.count(preSum - goal)) {
    //       res += map[preSum - goal];
    //     }
    //     map[preSum]++;
    //   }
    //   return res;
    // }


/*
prefixSum + hash
0 0 0 0 [1 XXXXX 1] 0 0 0 0 
                    r
we wnat all the possible of subarray
we already know how many left side zero
we dont know how many right side is
so for each round we fixed r and count the left

*/

    //Sliding window
    int numSubarraysWithSum(vector<int>& A, int S) 
    {       
        int n = A.size();
        vector<int>postZeros(n);
        int count = 0;
        for (int i=n-1; i>=0; i--)
        {
            postZeros[i] = count;
            if (A[i]==0)            
                count++;            
            else
                count = 0;
        }
        
        int j = 0, sum = 0;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            while (j<=i || (j<n && sum < S))
            {
                sum += A[j];
                j++;
            }
            
            if (sum==S)
                ret += postZeros[j-1]+1;
            sum -= A[i]; 
        }
        
        return ret;        
    }
};



/*
sliding window
window should be total subarray for last 1 index in subarray
so when we right is fixed, find all possible sub

while (right <　n)
 find the rihgt
 fixed right found all possible sub
 res += all possible sub
 [x x x x x x x x x x x]
    l               r
l is 0 and l-1 is another 1 that 
right is (goal + 1 ) 1's


conor case when goal is 0 and nums is 0 


*/
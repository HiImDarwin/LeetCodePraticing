// class Solution {
// public:
    // int longestOnes(vector<int>& nums, int k) {
    //   unordered_map<int,int> mp;
    //   mp[0] = -1;
    //   int count = 0;
    //   for(int i = 0; i < nums.size(); ++i) {
    //     if(nums[i] == 0) {
    //       count++;
    //       mp[count] = i;
    //     }
    //   }
    //   mp[++count] = nums.size();
    //   int maxLen = 0;
    //   if(count-1 <= k ) return nums.size();
    //   for(int i = k+1; i <= count; i++) {
    //     maxLen = max(maxLen,mp[i] - mp[i-k-1] -1);
    //   }
    //   return maxLen;
    // }
// };


/* used prefix sum

the window minimun size is contina k+2 0
for ex  if k = 3

[1 1 1 1 0 1 1 1 1 0 1 0 1 1 1 0 1 1 0]
         1         2   3       4     5 

so the max length is index of 5 - index of 3 -1     

coner case when 0 number is less than k
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
      int n = nums.size();
      int count = 0;
      int i = 0;
      int ret = 0;
      for (int j=0; j<n; j++){
        if (nums[j] == 1) {
          ret = max(ret, j-i+1);
          continue;
        }
            
        count++;
        while (count>k) {
          if (nums[i]==0)
            count--;
          i++;
        }
        ret = max(ret, j-i+1);
      }
      return ret;
    }
};
/* two pointer
left and right
when k's 0 in window extend right if right is 1
when k+1 0 in window move left

edge case > when k = 0 what will happend


[1 1 1 1 0 1 1 0 1 1 0 0 1 ]




*/
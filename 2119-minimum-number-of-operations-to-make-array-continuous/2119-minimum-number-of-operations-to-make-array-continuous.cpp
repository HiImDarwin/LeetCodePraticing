class Solution {
public:
    int minOperations(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      unordered_map<int,int> mp;
      int n = nums.size();
      int maxAmount = 0;
      int duplicateCount = 0;
      for (int left = 0, right = 0; left < n; left++) {
        if (left != 0 && --mp[nums[left - 1]] > 0) {
          duplicateCount--;
        }
        while (right < n && nums[right] <= nums[left] + n - 1) {
          if (++mp[nums[right]] > 1) {
            duplicateCount++;
          }
          right++;
        }
        maxAmount = max(maxAmount, right - left - duplicateCount);
      }
      return n - maxAmount;
    }
};


/*
max - min = num length elemetn - 1
>> the num in array must be continues (don't need in order)

  [1, 2, 6, 7, 8]

x: number exits
o: num not exist
[x,x,x,o,o,x,o,o,x,x,o,o,x,x,o,x,x,o,x]
 ---------------
 fix range for 11
 find the most element range than we can got the answer
11 x element
8  o element
range is i ~ i + (19 - 1)

suplicate num:  count duplicate num


*/
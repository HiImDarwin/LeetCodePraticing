class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
      return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums , int bound) {
      int res = 0, cur = 0;
      for (auto& num : nums) {
        cur = num <= bound ? cur + 1 : 0;
        res += cur;
      }
      return res;
    }
};

/*
find  maximum in subarrays

deque

[2,1,4,3]

 smaller  < target[] < bigger

smaller in queue
  fix left keep finding target

target[]
  keep going until meet bigeer

meet bigeer
  pop all element in queue

when no [left, right] in queue go until find 
if num > right pop all out
when [left, right] int queue go right until find larger



*/
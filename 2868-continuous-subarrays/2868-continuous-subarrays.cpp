class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
      int n = nums.size();
      deque<int> maxdq,mindq;
      long long res = 0;
      for(int i = 0, j = 0; j < nums.size(); ++j) {
        // maximum deque (monotonic decrease)
        while(!maxdq.empty() && nums[j] > nums[maxdq.back()]) {
          maxdq.pop_back();
        }
        maxdq.push_back(j);
        // minimum deque (monotonic increase)
        while(!mindq.empty() && nums[j] < nums[mindq.back()]) {
          mindq.pop_back();
        }
        mindq.push_back(j);

        while(nums[maxdq.front()] - nums[mindq.front()] > 2) {
          if(!maxdq.empty() && maxdq.front() == i) {
            maxdq.pop_front();
          }
          if(!mindq.empty() && mindq.front() == i) {
            mindq.pop_front();
          }
          i++;
        }
        res += j - i + 1; 
      }
      return res;
    }
};

/*

  mantain a sliding window for each index j
  window left side is i


  1 2 3 1 2 4 2

*/
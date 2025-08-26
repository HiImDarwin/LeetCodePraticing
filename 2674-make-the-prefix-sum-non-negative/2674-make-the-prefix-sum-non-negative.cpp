class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
      priority_queue<int,vector<int>,greater<>> pq;
      long long sum = 0;
      int count = 0;
      for (auto& num : nums) {
        if (num < 0) {
          pq.push(num);
        }
        sum += num;
        if (sum  < 0) {
          int currentSmallest= pq.top();
          pq.pop();
          sum -= currentSmallest;
          count++;
        }
      }
      return count;
    }
};
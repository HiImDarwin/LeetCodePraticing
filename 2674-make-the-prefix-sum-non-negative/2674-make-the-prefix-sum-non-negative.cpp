class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
      priority_queue<int,vector<int>,greater<>> pq;
      long long sum = 0;
      int count = 0;
      for (auto& num : nums) {
        sum += num;
        if (num < 0) {
          pq.push(num);
        }
        while (sum < 0) {
          sum -= pq.top();
          pq.pop();
          count++;
        }
      }
      return count;

    }
};

/*


*/
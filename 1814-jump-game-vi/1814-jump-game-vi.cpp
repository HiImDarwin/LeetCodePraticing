class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n = nums.size();
      deque<pair<int,int>> dq;
      dq.push_back(pair{nums[0], 0});
      
      for (int i = 1; i < n; i++) {
        while (!dq.empty() && i - k > dq.front().second) {
          dq.pop_front();
        }
        int maxScore = nums[i] + (dq.empty() ? 0 : dq.front().first);
        while (!dq.empty() && maxScore >= dq.back().first) {
          dq.pop_back();
        }
        dq.push_back({maxScore, i});
      }

      return dq.back().first; 
    }
};

/*

dp O(nk)

dp + deque O(n)
deque manage minimum in a fixed winow



*/
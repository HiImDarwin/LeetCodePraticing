class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
      int N = nums.size();
      deque<pair<int,int>> smallerQ,largerQ;
      int windowLeft = -1;
      long long res = 0;
      for (int i = 0; i < N; i++){
        while (!smallerQ.empty() && nums[i] <= smallerQ.back().first) {
          smallerQ.pop_back();
        }
        smallerQ.push_back({nums[i],i});
        while (!largerQ.empty() && nums[i] >= largerQ.back().first) {
          largerQ.pop_back();
        }

        largerQ.push_back({nums[i],i});
        
        while(nums[i] - smallerQ.front().first > 2 || largerQ.front().first - nums[i] > 2) {
          windowLeft++;
          if (smallerQ.front().second == windowLeft) {
            smallerQ.pop_front();
          }
          if (largerQ.front().second == windowLeft) {
            largerQ.pop_front();
          }
        }

        res += i - windowLeft;
      }
      return res;
    }
};

/*

you want to find prev smaller prev bigger and you need to find the length of window



12134

3   4
3


*/
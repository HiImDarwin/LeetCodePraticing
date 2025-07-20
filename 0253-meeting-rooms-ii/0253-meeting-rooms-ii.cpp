class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      int res = 0;
      int count = 0;
      int n = intervals.size();
      vector<int> arrive,leave;
      for(auto interval :intervals) {
        arrive.push_back(interval[0]);
        leave.push_back(interval[1]);
      }
      sort(arrive.begin(),arrive.end());
      sort(leave.begin(),leave.end());
      int i = 0, j = 0;
      while( i < n && j < n ) {
        if(arrive[i] < leave[j]) {
          count++;
          i++;
        } else if(arrive[i] == leave[j]) {
          i++;
          j++;
        } else {
          count--;
          j++;
        }
        res = max(res,count);
      }
      return res;
    }
};
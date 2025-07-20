class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      int maxRoom = 0;
      int room = 0;
      int n = intervals.size();
      vector<pair<int,int>> timeLine;
      for(auto interval :intervals) {
        timeLine.push_back({interval[0],1});
        timeLine.push_back({interval[1],-1});
      }
      sort(timeLine.begin(),timeLine.end());
      for(auto [time, delta] : timeLine){
        room += delta;
        maxRoom = max(maxRoom,room);
      }
      return maxRoom;
    }
    
};
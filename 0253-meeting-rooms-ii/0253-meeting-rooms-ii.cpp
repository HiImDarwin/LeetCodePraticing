class Solution {
public:
    // int minMeetingRooms(vector<vector<int>>& intervals) {
    //   int maxRoom = 0;
    //   int room = 0;
    //   int n = intervals.size();
    //   vector<pair<int,int>> timeLine;
    //   for(auto interval :intervals) {
    //     timeLine.push_back({interval[0],1});
    //     timeLine.push_back({interval[1],-1});
    //   }
    //   sort(timeLine.begin(),timeLine.end());
    //   for(auto [time, delta] : timeLine){
    //     room += delta;
    //     maxRoom = max(maxRoom,room);
    //   }
    //   return maxRoom;
    // }  
    int minMeetingRooms(vector<vector<int>>& intervals) {
      vector<int> time(1e6+1,0);
      for (auto& interval : intervals) {
        time[interval[0]]++;
        time[interval[1]]--;
      }
      int res = 0;
      int current = 0;
      for (int i = 0; i < time.size(); i++) {
        current += time[i];
        res = max(res,current);
      }
      return res;
    }
};



/*

    XXX
  XXXX
XXX

at the moment how many meeting overlap






*/
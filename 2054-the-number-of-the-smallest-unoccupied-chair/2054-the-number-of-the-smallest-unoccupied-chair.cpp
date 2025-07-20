class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
      int n = times.size();
      vector<int> seat(n,-1);
      priority_queue<int,vector<int>, greater<>> seatQueue;
      priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> arriveQueue;

      for(int i = 0; i < n ; ++i) {
        seatQueue.push(i);
      }

      for(int i = 0; i < n ;++i) {
        int arrive = times[i][0];
        int leave = times[i][1];
        arriveQueue.push({arrive, 1, i});
        arriveQueue.push({leave, 0, i});
      }

      while(!arriveQueue.empty() && seat[targetFriend] == -1) {
        auto [time, type, person] = arriveQueue.top();
        arriveQueue.pop();
        if(seat[person] == -1) {
          int emptySeat = seatQueue.top(); seatQueue.pop();
          seat[person] = emptySeat;
        } else {
          int nonEmptySeat = seat[person];
          seatQueue.push(nonEmptySeat);
          seat[person] == -1;
        }
      }

      return seat[targetFriend];
    }
};

/*
how to find smallest seat?



*/
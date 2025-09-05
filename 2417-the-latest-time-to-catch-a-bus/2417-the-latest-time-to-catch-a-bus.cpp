class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
      sort(buses.begin(), buses.end());
      sort(passengers.begin(), passengers.end());
      int pasIdx = 0;
      int lastTime = 0;
      int prev = -1;

      for (int busIdx = 0; busIdx < buses.size(); busIdx++) {
        int waiting = 0;
        while (waiting < capacity && pasIdx < passengers.size() && passengers[pasIdx] <= buses[busIdx]) {
          if(prev != passengers[pasIdx] - 1) {
            lastTime = passengers[pasIdx] - 1;
          }
          prev = passengers[pasIdx];
          waiting++;
          pasIdx++;
        }
        if (waiting < capacity && prev != buses[busIdx]) {
          lastTime = buses[busIdx];
        }
      }
      return lastTime;

    }
};

/*
[0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1]


*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int gain = 0, currGain = 0;
      int res = 0;
      for (int i = 0; i < n; i ++) {
        gain += gas[i] - cost[i];
        currGain += gas[i] - cost[i];

        if (currGain < 0) {
          res = (i + 1) % n;
          currGain = 0;
        }
      }
      if (gain < 0) return -1;  
      return res;
    }
};



/*

4 7 10 5
6 8 9  2
-4 -2 8  -1


*/
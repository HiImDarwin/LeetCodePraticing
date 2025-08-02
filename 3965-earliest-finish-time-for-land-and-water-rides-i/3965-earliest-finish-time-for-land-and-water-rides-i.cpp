class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
      int n = landStartTime.size();
      int m = waterStartTime.size();
      int i = 0, j = 0;
      int res = INT_MAX;
      
      while (i < n) {
        int landStart = landStartTime[i];
        int landEnd = landStart + landDuration[i];
        j = 0;
        int tmp = INT_MAX;
        while (j < m ) {
          int endTime;
          if(waterStartTime[j] < landEnd) {
            endTime = landEnd + waterDuration[j];
          } else {
            endTime = waterStartTime[j] + waterDuration[j];
          }
          tmp = min(tmp, endTime);

          j++;
        }
        res = min(res, tmp);
        i++;
      }

      j = 0;
      while (j < m) {
        int waterStart = waterStartTime[j];
        int waterEnd = waterStart + waterDuration[j];
        i = 0;
        int tmp = INT_MAX;
        while (i < n) {
          int endTime;
          if(landStartTime[i] < waterEnd) {
            endTime = waterEnd + landDuration[i];
          } else {
            endTime = landStartTime[i] + landDuration[i];
          }
          tmp = min(tmp, endTime);
          i++;
        }
        res = min(res, tmp);
        j++;
      }
      return res;
    }
};


/*

2 6     8 9
  6 10    9 10

6 9
  9 12
*/
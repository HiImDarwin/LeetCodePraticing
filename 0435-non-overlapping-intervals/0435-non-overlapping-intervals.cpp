class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b) {
          return a[1]<b[1];
        });
        int tmp_val = intervals[0][1];
        int removeNum=0;
        for(int i = 1; i < intervals.size(); ++i) {
          if(intervals[i][0]<tmp_val){
            removeNum++;
          } else {
            tmp_val = intervals[i][1];
          }
        }
        return removeNum;
    }
};
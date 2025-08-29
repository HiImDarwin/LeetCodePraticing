class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
      // sort(clips.begin(), clips.end(), [](const vector<int>& a, const vector<int>& b){
      //   if (a[0] == b[0]) {
      //     a[1] > b[1];
      //   }
      //   return a[0] < b[0];
      // });
      sort(clips.begin(), clips.end());
      if (clips[0][0] != 0) return -1;

      int n = clips.size();
      int right = 0;
      int clipsCount = 0;
      int idx = 0;
      
      while (idx < n) {
        int newRight = right;
        if (newRight >= time) {
          break;
        }

        while (idx < n && clips[idx][0] <= right) {
          newRight = max(newRight,clips[idx][1]);
          idx++;
        }

        if (newRight == right) {
          return -1;
        }
        right = newRight;
        clipsCount++;
      }

      return right < time ? -1 : clipsCount;
    }
};

/*

XXXXX XXXXX XXXXX 
   XXXXX XXXXX

1. find non overlaping interval (pick the longer one)



*/
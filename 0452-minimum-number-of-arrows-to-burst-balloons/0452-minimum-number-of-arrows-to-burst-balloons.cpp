class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
        return a[0]<b[0];
      });
      int ans=1;
      int overlap_left = points[0][1], overlap_right = points[0][1];
      for(int i = 1; i < points.size(); ++i){
        if(points[i][0] <= overlap_right){
            overlap_left = max(overlap_left, points[i][0]);
            overlap_right = min(overlap_right, points[i][1]);
        } else{
            ans++;
            overlap_left = points[i][0];
            overlap_right = points[i][1];
        }
      }
      return ans;
    }
};
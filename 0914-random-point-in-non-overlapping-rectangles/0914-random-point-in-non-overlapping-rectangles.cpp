class Solution {
  vector<vector<int>> rects;
  vector<int> q;
public:
    Solution(vector<vector<int>>& rects): rects(rects) {
      int sum= 0;
      for (int i = 0; i < rects.size(); ++i) {
        sum += (rects[i][2]-rects[i][0]+1) * (rects[i][3]-rects[i][1]+1);
        q.push_back(sum);
      }
      this->rects = rects;
    }
    
    vector<int> pick() {
      int idx = rand()%q.back();
      int i = lower_bound(q.begin(),q.end(), idx+1) - q.begin();
      int pos = idx - ((i > 0) ? q[i-1] : 0);
      int width = rects[i][3] - rects[i][1] + 1;
      int x = rects[i][0]+ pos/width;
      int y = rects[i][1]+ pos%width;
      return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
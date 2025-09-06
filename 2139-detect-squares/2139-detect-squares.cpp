class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
       int x = point[0];
       int y = point[1];
       if (freq.find({x, y}) == freq.end()) {
        axisXmap[x].push_back({x, y});
       }
       freq[{x,y}]++;
    }
    
    int count(vector<int> point) {
      int x = point[0];
      int y = point[1];
      int count = 0;
      for (auto [x2, y2] : axisXmap[x]) {
        int len = abs(y2 - y);
        if (len == 0) continue;
        if (freq.find({x + len , y}) != freq.end() && freq.find({x + len , y2}) != freq.end()) {
          count += freq[{x + len, y}] * freq[{x2, y2}] *  freq[{x + len, y2}];
        }

        if (freq.find({x - len , y})!= freq.end() && freq.find({x - len , y2}) != freq.end()) {
          count += freq[{x - len, y}] * freq[{x2, y2}] *  freq[{x - len, y2}];
        }
      }
      return count;
    }
  private:
    unordered_map<int,vector<pair<int,int>>> axisXmap;
    map<pair<int,int>, int> freq;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);

 // record each point num

 
   *


 * find

 */
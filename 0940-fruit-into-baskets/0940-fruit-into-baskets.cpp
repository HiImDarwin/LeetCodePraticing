class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n = fruits.size();
      map<int,int> segment;
      for (int i = 0, start = 0; i < n; i++) {
        if (fruits[i] != fruits[start]) {
          segment[start] = i - start;
          start = i;
        } 
        if (i == n-1) {
          segment[start] = i - start + 1;
        }
      }
      int prevPoint1 = -1;
      int prevPoint2 = -1;
      int total = 0;
      int res = 0;
      for (auto& [start , count]: segment) {
        if (prevPoint1 == -1 || prevPoint2 == -1) {
          total += count;
        } else if (fruits[start] == fruits[prevPoint2]) {
          total += count;
        } else {
          res = max(res, total);
          total = segment[prevPoint1] + segment[start];
        }
        prevPoint2 = prevPoint1;
        prevPoint1 = start;
      }
      res = max(res, total);
      return res;
    }
};

/*

1 2 3 1 222 3333 222 333 11 2
    


segment 

*/
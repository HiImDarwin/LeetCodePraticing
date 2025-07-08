class Solution {
  //int res;
  public:
    // int minAreaRect(vector<vector<int>>& points) {
    //   int n = points.size();
    //   unordered_map<int,vector<pair<int,int>>> mp;
    //   res = INT_MAX;
    //   for(int i =0; i < n; ++i) {
    //     for(int j = i+1; j < n; ++j) {
    //       int x1 = points[i][0], x2 = points[j][0];
    //       int y1 = points[i][1], y2 = points[j][1];
    //       if(y1 != y2) continue;
    //       if(x1 > x2) {
    //         swap(x1,x2);
    //       }
    //       findRetangel(mp,y1,x1,x2);
    //       mp[y1].push_back(make_pair(x1,x2));
          
    //     }
    //   }
    //   return res== INT_MAX ? 0 : res;
    // }

    // void findRetangel(unordered_map<int,vector<pair<int,int>>> &mp, int y, int x1, int x2) {
    //   for(auto &lines : mp){
    //     if (lines.first == y) continue;
    //     for(auto line : lines.second) {
    //       if(line.first == x1 && line.second == x2) {
    //         res = min(res,abs(y -lines.first) * (x2 - x1));
    //         break;
    //       }
    //     }
    //   }
    // }

    int minAreaRect(vector<vector<int>>& points) {
      unordered_map<int,unordered_set<int>> Map;
      int res = INT_MAX;
      for (auto p : points){
        Map[p[0]].insert(p[1]);
      }
      for(int i = 0; i< points.size(); i++) {
        for(int j = i+1; j <points.size(); j++) {
          int x1 = points[i][0];
          int y1 = points[i][1];
          int x2 = points[j][0];
          int y2 = points[j][1];
          if(x1 == x2 || y1 == y2) continue;
          if(Map[x1].count(y2) && Map[x2].count(y1)) {
            res = min(res, abs(x1-x2)*abs(y1-y2));
          }
        }
      }
      return res == INT_MAX ? 0 : res;
    }
};
/*
官神

先想快的方法，在去想快的數據結構


只要兩點就可以確定一個唯一舉行 (對角線)
A     C

D     B

O(N*N)
for A = ...
  for B = ...
    if(C,D) in set
      area = ...
        res = min(res, area)




*/



/*
for any two point if their can be horizental line (y1 == y2)
keep there x1 and x2 in pair
we can find another horizental line (y3 != y1) and x3 = x1 and x4 = x2
to build an rectangle
how to iterator all node?

how to storage?

Question

1. will we get same point in points
2. should the rectangel parallel to x and y axes

*/
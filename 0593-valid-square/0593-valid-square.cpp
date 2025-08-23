class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
      unordered_set<int> distantSet;
      distantSet.insert(distant(p1,p2));
      distantSet.insert(distant(p1,p3));
      distantSet.insert(distant(p1,p4));
      distantSet.insert(distant(p2,p3));
      distantSet.insert(distant(p2,p4));
      distantSet.insert(distant(p3,p4));
      
      return (distantSet.size() == 2) && (distantSet.count(0) == 0);
      
    }

    int distant(const vector<int>& a, const vector<int>& b) {
      return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};

/*
a square
1. 90 degree
2. edge length equeal


*/
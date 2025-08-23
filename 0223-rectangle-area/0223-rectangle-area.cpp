class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      if(ax1 > bx1) {
        return computeArea(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2);
      }
      int areaA = (ax2 - ax1) * (ay2 - ay1);
      int areaB = (bx2 - bx1) * (by2 - by1);
      cout << "A: " << areaA << " B: " << areaB << endl;

      if (ax2 <= bx1 || ay1 >= by2 || ay2 <= by1) {
        return areaA + areaB; 
      } else if (ax1 <= bx1 && ax2 >= bx2 && ay1 <= by1 && ay2 >= by2) {
        return areaA;
      } 

      vector<int> Xpoints = {ax1, ax2, bx1, bx2};
      vector<int> Ypoints = {ay1, ay2, by1, by2};
      sort(Xpoints.begin(), Xpoints.end());
      sort(Ypoints.begin(), Ypoints.end());
      return areaA + areaB - (Xpoints[2] - Xpoints[1]) * (Ypoints[2] - Ypoints[1]);   
    }
};



/*

x y no overlap 

x overlap y not overlap
y overlap x not overlap

x y overlap


total cover
x1 < 


*/
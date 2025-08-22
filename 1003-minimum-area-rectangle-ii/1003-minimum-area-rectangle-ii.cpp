class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
      map<pair<int,int>,vector<pair<int,int>>> mp;
      int N = points.size();

      for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
          if (i == j) continue;
          int dx = points[i][0] - points[j][0]; 
          int dy = points[i][1] - points[j][1];
          if (dx < 0) {
            dx = -dx;
            dy = -dy;
            mp[{dx,dy}].push_back({j,i});
          } else {
            mp[{dx,dy}].push_back({i,j});
          }
          
        }
      }
      

      double res = DBL_MAX;

      for (auto item: mp) {
        for (int m = 0; m < item.second.size(); m++) {
          for (int n = m+1; n < item.second.size(); n++) {
            int i = item.second[m].first;
            int j = item.second[m].second;
            int k = item.second[n].first;
            
            int dx1 = points[i][0] - points[j][0];
            int dy1 = points[i][1] - points[j][1];

            int dx2 = points[i][0] - points[k][0];
            int dy2 = points[i][1] - points[k][1];
            if (dx1 * dx2 + dy1 * dy2 != 0) continue;
            double side1 = dx1*dx1 + dy1*dy1;
            double side2 = dx2*dx2 + dy2*dy2;
            double area = sqrt(side1) * sqrt(side2);

            res = min (res, area);
          }
        }
      }


      return  res == DBL_MAX ? 0 : res;
      
    }
};




/*
{x1,y1} * {x2,y2} = x1*x2 + y1*y2 
相量相乘＝0. 矩型

vector內儲存兩點符合該斜率的 points index
map[dxdy] = [{1,2},{4,12}...] 

*/
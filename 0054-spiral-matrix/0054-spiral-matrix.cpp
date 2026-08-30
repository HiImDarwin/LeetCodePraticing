class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int hight = matrix.size();
    if (hight == 0) {
       return {};
    }
    int width = matrix[0].size();
    if (width == 0) {
       return {};
    }
    int dir = 0;
    int step = width - 1;
    int xIdx = 0, yIdx = 0;
    int remain = width * hight;
    vector<int> res;
    res.push_back(matrix[0][0]);
    remain--;
    while (remain > 0) {
      while (step > 0) {
        xIdx += shift[dir].first;
        yIdx += shift[dir].second;
        res.push_back(matrix[xIdx][yIdx]);
        remain--;
        step--;
      }

      dir = (dir + 1) % 4;
      if (dir % 2 == 0) {
        width -= 1;
        step = width;
      } else {
        hight -= 1;
        step = hight;
      }
    }
    return res;      
  }

private:
  const pair<int,int> shift[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};



/*
the point is the you need to 
1. write the value
2. set next idx

x x x x 
x x x x 
x x x x 
x x x x 
x x x x 

*/
class Solution {
public:
  // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
  //   int ori = image[sr][sc];
  //   if (ori == color) {
  //     return image;
  //   }
  //   int height = image.size();
  //   int width = image[0].size();
  //   queue<pair<int,int>> qu;
  //   qu.push({sr,sc});
  //   image[sr][sc] = color;
  //   while(!qu.empty()) {
  //     auto [x, y] = qu.front();
  //     qu.pop();
  //     for (auto& [dx, dy] : dir) {
  //       if (x + dx < 0 || x + dx >= height || y + dy < 0 || y + dy >= width) {
  //         continue;
  //       }
  //       if (image[x + dx][y + dy] == ori) {
  //         image[x + dx][y + dy] = color;
  //         qu.push({x + dx, y + dy});
  //       }
  //     }
  //   }
  //   return image;
  // }

  vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] == color) {
      return image;
    }
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
  }

  void dfs(vector<vector<int>>& image, int x, int y,int ori_color, int tar_color) {
    if (image[x][y] != ori_color) {
      return;
    }
    image[x][y] = tar_color;
    for (auto& [dx, dy] : dir) {
      int nX = x + dx;
      int nY = y + dy;
      if (nX < 0 || nX >= image.size() || nY < 0 || nY >= image[0].size()) {
        continue;
      }
      dfs(image, nX, nY, ori_color, tar_color);
    }
  }
};
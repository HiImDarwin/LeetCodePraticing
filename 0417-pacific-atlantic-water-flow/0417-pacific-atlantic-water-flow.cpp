class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // -1 for uncheck / 0 for can't reach / 1 for reachable
        vector<vector<bool>> toPacific(m,vector<bool> (n,false)),
                             toAtlantic(m,vector<bool> (n,false));
        
        vector<vector<int>> res;

        for(int i = 0; i < m; ++i){
          DFS(heights, toPacific, i, 0);
          DFS(heights, toAtlantic, i, n-1);
        }
        for(int j = 0; j < n; ++j) {
          DFS(heights, toPacific, 0, j);
          DFS(heights, toAtlantic, m-1, j);
        }

        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if(toPacific[i][j] && toAtlantic[i][j]) {
              res.push_back({i,j});
            }
          }
        }
        return res;
    
    }

    void DFS(vector<vector<int>>& heights, vector<vector<bool>> &rainMap,int xIdx, int yIdx) {
      int m =heights.size(), n = heights[0].size();
      rainMap[xIdx][yIdx] = true;
      if(xIdx-1 > -1 && heights[xIdx-1][yIdx] >= heights[xIdx][yIdx] && !rainMap[xIdx-1][yIdx])
        DFS(heights , rainMap, xIdx-1, yIdx);
      if(xIdx+1 < m && heights[xIdx+1][yIdx] >= heights[xIdx][yIdx] && !rainMap[xIdx+1][yIdx])
        DFS(heights , rainMap, xIdx+1, yIdx);
      if(yIdx-1 > -1 && heights[xIdx][yIdx-1] >= heights[xIdx][yIdx] && !rainMap[xIdx][yIdx-1])
        DFS(heights , rainMap, xIdx, yIdx-1);
      if(yIdx+1 < n && heights[xIdx][yIdx+1] >= heights[xIdx][yIdx] && !rainMap[xIdx][yIdx+1])
        DFS(heights , rainMap, xIdx, yIdx+1);
    }
};
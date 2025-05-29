class Solution {
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        int count = 0;
        int rows = grid2.size();
        int cols = grid2[0].size();

        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid2[i][j] == 1) {
                    // Pass rows and cols to the DFS function
                    res = true;
                    subIslandDFS(grid1, grid2, i, j, rows, cols);
                    if(res) count++;
                }
            }
        }
        return count;
    }

private:
    std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool res;

    void subIslandDFS(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2, int x, int y, int rows, int cols) {
        grid2[x][y] = 0; 
        if(grid1[x][y] == 0) res = false;

        for(auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid2[nx][ny] == 1) {
                 subIslandDFS(grid1, grid2, nx, ny, rows, cols);
            }
        }
    }
};
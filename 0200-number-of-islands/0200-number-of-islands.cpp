class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    DFS(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    int m;
    int n;
    const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = 0;
        for(const pair<int,int> &p: dirs) {
            int nx = x+p.first;
            int ny = y+p.second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]== '1') {
                DFS(grid,nx,ny);
            }
        }
    }
};
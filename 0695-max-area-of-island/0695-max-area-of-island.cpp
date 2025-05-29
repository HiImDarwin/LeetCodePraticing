class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        int res = 0;
        for( int i=0; i<x ;i++) {
            for (int j=0; j<y; j++) {
                if(grid[i][j]==1) {
                    int area =  DFS(grid,i,j);
                    res = area>res ? area: res;
                }
            }
        }
        return res; 
    }

    int DFS(vector<vector<int>> &grid, int x, int y) {
        stack<pair<int,int>> st;
        int border_x = grid.size();
        int border_y = grid[0].size();
        st.push({x,y});
        grid[x][y] = -1;
        int count =0;
        while(!st.empty()) {
            auto[r,c] = st.top();
            st.pop();
            count++;
            for(auto [dx,dy] : dirs){
                if(r+dx>=0 && r+dx <border_x && c+dy >=0 && c+dy<border_y && grid[r+dx][c+dy] == 1) {
                    st.push({r+dx,c+dy});
                    grid[r+dx][c+dy] = -1;
                }
            }
        }
        return count;
    }
const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
};
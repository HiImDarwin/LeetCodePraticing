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
        int count =0;
        while(!st.empty()) {
            auto[r,c] = st.top();
            st.pop();
            if(grid[r][c]!= 1) continue;
            grid[r][c] = -1;
            count++;
            if(c+1 <  border_y && grid[r][c+1] == 1) st.push({r,c+1});
            if(c-1 >= 0 && grid[r][c-1] == 1) st.push({r,c-1});
            if(r+1 <  border_x && grid[r+1][c] ==1) st.push({r+1,c});
            if(r-1 >= 0 && grid[r-1][c] ==1) st.push({r-1,c});          
        }
        return count;
    }
};
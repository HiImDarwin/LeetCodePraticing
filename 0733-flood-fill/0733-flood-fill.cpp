class Solution {
public:

    // ***************DFS******************
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     if(image[sr][sc] == color) return image;
    //     DFS(image, sr,sc,image.size(),image[0].size(),color,image[sr][sc]);
    //     return image;

    // }
    // void DFS(vector<vector<int>>& image, int sr, int sc, int x,int y, int color, int originCol){
    //     if(sr <0 || sc <0 || sr>=x || sc>=y) return;
    //     if(image[sr][sc] == originCol) image[sr][sc] = color;
    //     else return;
    //     DFS(image, sr-1,sc,x,y,color,originCol);
    //     DFS(image, sr,sc+1,x,y,color,originCol);
    //     DFS(image, sr,sc-1,x,y,color,originCol);
    //     DFS(image, sr+1,sc,x,y,color,originCol);
    //     return;
    // }

    // ***************BFS******************
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int originalCol = image[sr][sc];
        int x = image.size();
        int y = image[0].size();
        BFS(image,sr,sc,x,y,color,originalCol);
        return image;
    }

    void BFS (vector<vector<int>> &image,int sr,int sc,int x,int y,int color,int originalCol) {
        queue<pair<int,int>> qu;
        qu.push({sr,sc});
        while(!qu.empty()) {
            //pair<int,int> location = qu.front();
            auto [r,c] = qu.front();
            qu.pop();
            image[r][c] = color;
            if(r+1 < x && image[r+1][c] == originalCol) qu.push({r+1,c});
            if(r-1 >= 0 && image[r-1][c] == originalCol) qu.push({r-1,c});
            if(c+1 < y && image[r][c+1] == originalCol) qu.push({r,c+1});
            if(c-1 >= 0 && image[r][c-1] == originalCol) qu.push({r,c-1});
        }        
    }
};
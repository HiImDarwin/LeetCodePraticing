class Solution {
public:

    // ***************DFS******************
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        DFS(image, sr,sc,image.size(),image[0].size(),color,image[sr][sc]);
        return image;

    }
    void DFS(vector<vector<int>>& image, int sr, int sc, int x,int y, int color, int originCol){
        if(sr <0 || sc <0 || sr>=x || sc>=y) return;
        if(image[sr][sc] == originCol) image[sr][sc] = color;
        else return;
        DFS(image, sr-1,sc,x,y,color,originCol);
        DFS(image, sr,sc+1,x,y,color,originCol);
        DFS(image, sr,sc-1,x,y,color,originCol);
        DFS(image, sr+1,sc,x,y,color,originCol);
        return;
    }

    // ***************BFS******************
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    // }
};
class Solution {
public:
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     vector<int> res;
    //     // detemin round and distance
    //     // horizental go 1 + x-1 round
    //     // each round go y-1 , y-1-i step
    //     // vertical go x-1 round
    //     // each round go x-1-i step
    //     int x = matrix.size(); 
    //     int y = matrix[0].size();
    //     int round = min(x,y);

    //     for(int r=0;r<round;r++){
    //         // horizental
    //         for(int i = 0; i < y-r ; i++) {
    //             if(r%2==0) {
    //                 res.push_back(matrix[r/2][r/2+i]);
    //             } else {
    //                 res.push_back(matrix[(x-1)-r/2][y-2-r/2-i]);
    //             }
    //         }
    //         for(int i=0; i<x-1-r; i++) {
    //             if(r%2==0) {
    //                 res.push_back(matrix[r/2+1+i][y-1-r/2]);
    //             } else {
    //                 res.push_back(matrix[x-2-r/2-i][r/2]);
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bot = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> res;
        while(top <= bot && left <= right) {
            //top
            for(int i= left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            if(++top > bot) break;
            //right
            for(int i=top;i<=bot;i++){
                res.push_back(matrix[i][right]);
            }
            if(--right<left) break;
            //bot
            for(int i=right;i>=left;i--){
                res.push_back(matrix[bot][i]);
            }
            if(--bot < top) break;
            //left
            for(int i=bot; i>=top; i--) {
                res.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int top = 0;
        int bot = n-1;
        int left=0;
        int right = n-1;
        int index=1;

        while(top<=bot && left<=right) {
            //top
            for(int i = left;i<=right;i++) {
                res[top][i] = index++;
            }
            if(++top > bot) break;
            //right
            for(int i=top; i<=bot; i++){
                res[i][right] = index++;
            }
            if(--right < left) break;
            //bot
            for(int i=right; i>=left; i--){
                res[bot][i] = index++;
            }
            if(--bot < top) break;
            //left
            for(int i=bot;i>=top; i--){
                res[i][left] = index++;
            }
            if(++left >right) break;
        }
        return res;
    }
};
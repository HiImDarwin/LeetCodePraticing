class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> tmp(n,0);
        tmp[0]=1;
        int i=0,j;
        while(i<m){
            j=1;
            if(obstacleGrid[i][0]==1) tmp[0] = 0;
            while(j<n){
                if(obstacleGrid[i][j]!=1) {
                    tmp[j] = tmp[j-1]+tmp[j];
                } else {
                    tmp[j] = 0;
                }
                j++;
            }
            i++;
        }
        return tmp[n-1];
    }
};
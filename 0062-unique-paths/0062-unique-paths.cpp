class Solution {
public:
    // Combination
    // int uniquePaths(int m, int n) {
    //     int a,b;
    //     if(m>n){
    //         a=m-1;
    //         b=n-1;
    //     } else {
    //         a=n-1;
    //         b=m-1;
    //     }
    //     double res=1;
    //     for (int i=1;i<=b;i++) {
    //         res =res*(a+i) /i ;
    //     }
    //     return (int)res;
    // }

    // d[i][j] = j[i-1][j] + d[i][j-1]
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                dp[j] += dp[j-1];
            }
        }
        return  dp[n-1];
    }
};

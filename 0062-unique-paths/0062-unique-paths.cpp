class Solution {
public:
    int uniquePaths(int m, int n) {
        int a,b;
        if(m>n){
            a=m-1;
            b=n-1;
        } else {
            a=n-1;
            b=m-1;
        }
        double res=1;
        for (int i=1;i<=b;i++) {
            res =res*(a+i) /i ;
        }
        return (int)res;
    }
};

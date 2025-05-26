//top down
// class Solution {
// public:
//     int fib(int n) {
//         if (n < 2) return n;
//         vector<int> res(n+1,-1);
//         res[0] = 0;
//         res[1] = 1;
//         return fib(n,res);
//     }
//     int fib(int n, vector<int> &arr) {
//         if (arr[n-1] == -1) arr[n-1] = fib(n-1,arr);
//         if (arr[n-2] == -1) arr[n-2] = fib(n-2,arr);
//         arr[n] = arr[n-1]+arr[n-2];
//         return arr[n];
//     }
// };

//bottom up
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<int> res(n+1,-1);
        res[0]=0;
        res[1]=1;
        for(int i=2;i<n+1;i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};